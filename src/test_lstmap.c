/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:28:45 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/06 17:17:33 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function checks if the given char is a number or a letter.
*/

static t_list	*get_elem(t_list *elem, int index)
{
	if (index == 0 || elem == NULL)
		return (elem);
	else
		return (get_elem(elem->next, index - 1));
}

static int		log_error(t_list *lst1, t_list *(*f)(t_list *elem), t_list *lst2)
{
	int		i;
	
	ERROR_LOG
	i = 0;
	printf("file %s.\n", __FILE__);
	printf("function : %s\n", f == NULL ? "NULL" : "Not NULL");
	printf("original\t\t\t\t| mapped\n");
	while (get_elem(lst1, i) != NULL && get_elem(lst2, i) != NULL)
	{
		printf("elem %i : %s\t\t\t| elem %i : %s\n", i,
			   get_elem(lst1, i) == NULL ? "NULL\t" : "Not NULL",
			   i, get_elem(lst2, i) == NULL ? "NULL\t" : "Not NULL");
		printf("elem1 address\t\t\t\t!= elem2 address?\t%s\n",
			   get_elem(lst1, i) != get_elem(lst2, i)
			   ? "Yes" : "No");
		printf("content_size1 : %d\t\t\t| content_size2 : %d\n",
			   (int)(get_elem(lst1, i)->content_size),
			   (int)(get_elem(lst2, i))->content_size);
		printf("content_size1\t\t\t\t== content_size2?\t%s\n",
			   (get_elem(lst1, i))->content_size
			   == (get_elem(lst2, i))->content_size
			   ? "Yes" : "No");
		printf("content1 : %s\t\t\t| content2 : %s\n",
			   (get_elem(lst1, i))->content == NULL
			   ? "NULL\t" : "Not NULL",
			   (get_elem(lst2, i))->content == NULL
			   ? "NULL\t" : "Not NULL");
		printf("content1\t\t\t\t== content2?\t%s\n",
			   memcmp((get_elem(lst1, i))->content,
					  (get_elem(lst2, i))->content,
					  (get_elem(lst1, i))->content_size)
					  == 0 ? "Yes" : "No");
		printf("content1 address\t\t\t!= content2 address?\t%s\n",
			   (get_elem(lst1, i))->content
			   != get_elem(lst2, i)->content
			   ? "Yes" : "No");
		i++;
	}
	printf("elem %i : %s\t\t\t| elem %i : %s\n", i,
		   get_elem(lst1, i) == NULL ? "NULL\t" : "Not NULL",
		   i, get_elem(lst2, i) == NULL ? "NULL\t" : "Not NULL");
	return (0);
}

static t_list	*elemmap(t_list *elem)
{
	t_list	*result;

	result = ft_lstnew((*elem).content, (*elem).content_size);
	return (result);
}

static int		iscopy(t_list *lst1, t_list *lst2)
{
	if (lst1 == NULL && lst2 == NULL)
		return (1);
	if (lst1 == NULL || lst2 == NULL || lst1 == lst2)
		return (0);
	if (lst1->content == NULL && lst2->content == NULL
		&& lst1->content_size == lst2->content_size)
		return (iscopy(lst1->next, lst2->next));
	if (lst1->content == NULL || lst2->content == NULL)
		return (0);
	if (lst1->content_size == lst2->content_size
		&& memcmp(lst1->content, lst2->content,
				  lst2->content_size) == 0)
		return (iscopy(lst1->next, lst2->next));
	return (0);
}

static int		test_case(t_list *arg1, t_list *(*f)(t_list *elem))
{
	int		status;
	pid_t	pid;
	t_list	*elem;
	
	pid = fork();
	status = 0;
	if (pid < 0)
	{
		FORK_ERROR
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf(" - Case : elem : %s, f : %s.\n",
				   arg1 == NULL ? "(NULL)" : (char *)arg1, f == NULL ? "NULL" : "Not NULL");
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		elem = ft_lstmap(arg1, f);
		if (iscopy(arg1, elem))
			exit(EXIT_SUCCESS);
		log_error(arg1, f, elem);
		if (elem)
		{
			if (elem->content)
				free(elem->content);
			free(elem);
		}
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_lstmap(void)
{
	int		val;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	size_t	i;
	
	val = 1;
	elem1 = ft_lstnew(&val, sizeof(val));
	elem2 = ft_lstnew(NULL, 0);
	elem3 = ft_lstnew(&val, sizeof(val));
	elem1->next = elem2;
	elem2->next = elem3;
	t_list	*cases[] = {elem1, NULL};
	NAME_LOG("ft_lstmap()")
	i = 0;
	while (i < sizeof(cases)/sizeof(t_list *))
	{
		if (test_case(cases[i], elemmap) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
