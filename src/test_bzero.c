/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/24 05:23:14 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		log_error(char *str, size_t n)
{
	ERROR_LOG
	printf("file %s.\nArgs : %s (char *). %d (size_t).\n str weren't t\
he same after the function call.\n",
		   __FILE__, (char *)str, (int)n);
	return (0);
}

static int		test_case(void *arg1, size_t n)
{
	pid_t	pid;
	int		status;
	void	*cpy1;
	void	*cpy2;
	
	if (arg1 == NULL)
	{		
		cpy1 = NULL;
		cpy2 = NULL;
	}
	else
	{
		cpy1 = strndup(arg1, n);
		cpy2 = strndup(arg1, n);
	}
	pid = fork();
	status = EXIT_FAILURE;
	if (pid < 0)
	{
		FORK_ERROR
		free(cpy1);
		free(cpy2);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf(" - Case : %s, %d ", (char *)arg1, (int) n);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		ft_bzero(cpy1, n);
		bzero(cpy2, n);
		if (strncmp(cpy1, cpy2, n) == 0 || arg1 == NULL || n == 0)
		{
			free(cpy1);
			free(cpy2);
			exit(EXIT_SUCCESS);
		}
		log_error(arg1, n);
		free(cpy1);
		free(cpy2);
		exit(EXIT_FAILURE);
	}
	free(cpy1);
	free(cpy2);
	return (!status);
}

char		*randstr(void)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 11);
	i = 0;
	while (i < 10)
	{
		str[i] = (char) rand();
		i++;
	}
	str[i] = '\0';
	return (str);
}

int			test_bzero(void)
{
	char	*cases[][2] = {{NULL, "0"}, {"1", "0"}, {randstr(), "10"}, {"1111", "2"}};
	int		i;

	i = 0;
	NAME_LOG("ft_bzero()")
	while ((unsigned long)i < sizeof(cases) / sizeof(cases[0]))
	{
		if (test_case((void *)cases[i][0], (size_t)atoi(cases[i][1]))
			== 0)
		{
			free(cases[2][0]);
			return (0);
		}
		i++;
	}
	SUCCESS_LOG
	free(cases[2][0]);
	return (1);
}
