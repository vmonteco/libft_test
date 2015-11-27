/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:28:45 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/27 21:09:31 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function checks if the given char is a number or a letter.
*/

static int		log_error(t_list **alst, t_list *new)
{
	ERROR_LOG
	printf("file %s, alst : %s, new : %s\n", __FILE__, alst == NULL ? "NULL" : (*alst == NULL ? "Not NULL but *alst == NULL" : "Not NULL"), new == NULL ? "NULL" : "Not NULL");
	return (0);
}

static int		test_case(t_list **alst, t_list *new)
{
	pid_t	pid;
	int		status;
	t_list	*inter;
	
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
			printf(" - Case : alst : %s, new : %s.\n", alst == NULL ? "NULL" : (*alst == NULL ? "Not NULL but *alst == NULL" : "Not NULL"), new == NULL ? "NULL" : "Not NULL");
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		if (new == NULL || alst == NULL)
			exit(EXIT_SUCCESS);
		inter = *alst;
		ft_lstadd(alst, new);
		if (new == *alst && inter == (**alst).next)
			exit(EXIT_SUCCESS);
		log_error(alst, new);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_lstadd(void)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	size_t	i;
	int		val;
	
	val = 1;
	elem3 = NULL;
	elem1 = ft_lstnew(&val, sizeof(val));
	val = 2;
	elem2 = ft_lstnew(&val, sizeof(val));
	t_list	**cases_alst[] = {&elem1, &elem3, NULL};
	t_list	*cases_new[] = {elem2, elem2, NULL};
	NAME_LOG("ft_lstadd()")
	i = 0;
	while (i < sizeof(cases_new) / sizeof(t_list *))
	{
		if (test_case(cases_alst[i], cases_new[i]) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
