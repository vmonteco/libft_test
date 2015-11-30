/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/30 06:00:10 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		log_error(void *result, size_t size)
{
	int		flag;
	size_t	i;

	ERROR_LOG
	flag = (1 == 1);
	i = 0;
	while (result && i < size
		   && &(((unsigned char *)result)[i]))
	{
		flag = flag && ((unsigned char *)result)[i] == 0;
		i++;
	}
	printf("file %s.\nresult : %s (void *), size : %d\n",
		   __FILE__, result == NULL ? "NULL" : "Not NULL",
		   (int)size);
	return (0);
}

static int		test_case(size_t size)
{
	size_t	i;
	int		flag;
	void	*res;
	pid_t	pid;
	int		status;

	pid = fork();
	res = NULL;
	status = EXIT_FAILURE;
	if (pid < 0)
		FORK_ERROR
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf(" - Case : size == %d ", size);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res = ft_memalloc(size);
		flag = (1 == 1);
		i = 0;
		if (res == NULL && size == 0)
			exit(EXIT_SUCCESS);
		if (res != NULL && size > 0)
		{
			while (i < size)
			{
				flag = flag && ((unsigned char *)res)[i] == 0;
				i++;
			}
			if (flag)
			{
				free(res);
				exit(EXIT_SUCCESS);
			}
		}
		log_error(res, size);
		free(res);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_memalloc(void)
{
	size_t	cases[] = {0, 1, 10};
	int		i;

	i = 0;
	NAME_LOG("ft_memalloc()")
	while ((unsigned long)i < sizeof(cases) / sizeof(size_t))
	{
		if (test_case(cases[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
