/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:28:45 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/06 17:17:53 by vmonteco         ###   ########.fr       */
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

static int		log_error(t_list *lst, void (*f)(t_list *elem))
{
	int		i;
	
	ERROR_LOG
	i = 0;
	printf("file %s.\n", __FILE__);
	printf("function : %s\n", f == NULL ? "NULL" : "Not NULL");
	while (get_elem(lst, i) != NULL)
	{
		printf("elem %i : %s\n", i,
			   get_elem(lst, i) == NULL ? "NULL\t" : "Not NULL");
		printf("content_size = %d\n",
			   (int)(get_elem(lst, i)->content_size));
		printf("content_size == sizeof(0)?%s\n",
			   (get_elem(lst, i))->content_size
			   == sizeof(0) ? "Yes" : "No");
		printf("content : %s\n",
			   (get_elem(lst, i))->content == NULL
			   ? "NULL" : (*((int *)get_elem(lst, i)->content)
			   == 0 ? "0" : "Not 0"));
		i++;
	}
	printf("elem %i : %s\n", i,
		   get_elem(lst, i) == NULL ? "NULL" : "Not NULL");
	return (0);
}

static void		to_zero(t_list *elem)
{
	if (elem)
	{
		if (elem->content != NULL)
			free(elem->content);
		elem->content = malloc(sizeof(0));
		elem->content_size = sizeof(0);
		*((int *)elem->content) = 0;
	}
}

static int		get_size(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + get_size(lst->next));
}

static int		is_ok(t_list *lst, int i)
{
	if (get_size(lst) != i)
		return (0);
	if (lst == NULL)
		return (1);
	if (*((int *)(lst->content)) == 0
		&& lst->content_size == sizeof(0))
		return (is_ok(lst->next, i - 1));
	return (0);
}

static int		test_case(t_list *arg1, void (*f)(t_list *elem))
{
	int		status;
	pid_t	pid;
	int		size;
	
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
		size = get_size(arg1);
		ft_lstiter(arg1, to_zero); 
		if (is_ok(arg1, size))
			exit(EXIT_SUCCESS);
		log_error(arg1, f);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_lstiter(void)
{
	int		val;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	size_t	i;
	char	str[] = "test";
	
	val = 1;
	elem1 = ft_lstnew(&val, sizeof(val));
	elem2 = ft_lstnew(NULL, 0);
	elem3 = ft_lstnew(str, sizeof("test"));
	elem1->next = elem2;
	elem2->next = elem3;
	t_list	*cases[] = {elem1, NULL};
	NAME_LOG("ft_lstiter()")
	i = 0;
	while (i < sizeof(cases)/sizeof(t_list *))
	{
		if (test_case(cases[i], to_zero) != 1)
			return (0);
		i++;
	}
	if (test_case(NULL, NULL) != 1)
		return (0);
	SUCCESS_LOG
	return (1);
}
