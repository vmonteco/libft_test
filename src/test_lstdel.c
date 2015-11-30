/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:28:45 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/29 23:20:10 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function deletes one lst elem.
*/

static int		log_error(t_list **alst, void (*del)(void *, size_t))
{
	ERROR_LOG
	printf("file %s, alst : %s, del : %s\n", __FILE__, alst == NULL ? "NULL" : (*alst == NULL ? "Not NULL but *alst == NULL" : "Not NULL"), del == NULL ? "NULL" : "Not NULL");
	return (0);
}

static int		test_case(t_list **alst, void (*del)(void *, size_t))
{
	pid_t	pid;
	int		status;
	t_list	**inter;
	
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
			printf(" - Case : alst : %s, del : %s.\n", alst == NULL ? "NULL" : (*alst == NULL ? "Not NULL but *alst == NULL" : "Not NULL"), del == NULL ? "NULL" : "Not NULL");
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		if (alst && *alst)
			inter = &((**alst).next);
		ft_lstdel(alst, del);
		if (del == NULL || alst == NULL || *alst == NULL)
			exit(EXIT_SUCCESS);
		if (*alst == NULL && *inter == NULL)
			exit(EXIT_SUCCESS);
		log_error(alst, del);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

static void	delcontent(void *content, size_t content_size)
{
	int		i;

	free(content);
	i = (int)content_size;
	if (i)
		i = 0;
}

int			test_lstdel(void)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	size_t	i;
	int		val;
	
	val = 1;
	elem4 = NULL;
	elem1 = ft_lstnew(&val, sizeof(val));
	val = 2;
	elem2 = ft_lstnew(&val, sizeof(val));
	elem3 = ft_lstnew(&val, sizeof(val));
	elem2->next = elem3;
	t_list	**cases_alst[] = {&elem1, &elem2, &elem4, NULL};
	NAME_LOG("ft_lstdel()")
	i = 0;
	while (i < sizeof(cases_alst) / sizeof(t_list **))
	{
		if (test_case(cases_alst[i], delcontent) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
