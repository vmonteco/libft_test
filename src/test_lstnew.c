/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:28:45 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/27 20:38:15 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function checks if the given char is a number or a letter.
*/

static int		log_error(void *arg1, size_t arg2, t_list *elem)
{
	ERROR_LOG
	printf("file %s.\n", __FILE__);
	printf("Content : %s.\n", (arg1 == NULL ? "Null" : (char *)arg1));
	printf("Content_size : %d.\n", arg2);
	if (elem == NULL)
		printf("Result : NULL.\n");
	else
	{
		printf("Result : Not null.\n");
		printf("Result->content : %s.\n",
			   elem->content == NULL ? "Null" : (char *)elem->content);
		printf("Result->content_size : %d.\n", elem->content_size);
	}
	return (0);
}

static int		is_ok(void *arg1, size_t arg2, t_list *elem)
{
	if (elem == NULL)
		return (0);
	if (elem->content == NULL && arg1 == NULL && elem->content_size == 0)
		return (1);
	if (elem->content_size == arg2 && arg2 == 0 && elem->content == NULL && elem->next == NULL)
		return (1);
	if (arg1 != NULL && elem->content == NULL)
		return (0);
	if (arg1 == NULL && elem->content != NULL)
		return (0);
	if (arg1 != NULL && elem->content != NULL && elem->content_size == arg2 && memcmp(arg1, elem->content, sizeof(*arg1)) == 0 && elem->next == NULL)
		return (1);
	return (0);
}

static int		test_case(void *arg1, size_t arg2)
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
			printf(" - Case : content : %s, content_size : %d.\n",
				   arg1 == NULL ? "(NULL)" : (char *)arg1, arg2);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		elem = ft_lstnew(arg1, arg2);
		if (is_ok(arg1, arg2, elem))
			exit(EXIT_SUCCESS);
		log_error(arg1, arg2, elem);
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

int			test_lstnew(void)
{
	size_t		i;
	void		*cases_void[] = {NULL, (void *) "test", NULL,
								 "", "test"};
	size_t		cases_size_t[] = {0, sizeof("test"), 1,
								  10, 0};
	
	NAME_LOG("ft_lstnew()")
	i = 0;
	while (i < sizeof(cases_void)/sizeof(void*))
	{
		if (test_case(cases_void[i], cases_size_t[i]) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
