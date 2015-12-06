/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/06 17:54:31 by vmonteco         ###   ########.fr       */
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

static int		test_case(void *s1, const void *s2, size_t n)
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
			printf(" - Case : size == %d ", (int)size);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res = ft_memcpy(size);
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

int			test_memcpy(void)
{
	void	*cases_s1[] = {NULL};
	void	*cases_s2[] = {NULL};
	int		i;

	i = 0;
	NAME_LOG("ft_memcpy()")
	while ((unsigned long)i < sizeof(cases_s1) / sizeof(void *))
	{
		if (test_case(cases[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
