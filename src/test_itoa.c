/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:00:22 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/24 06:13:17 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "test.h"

/*
** This function should return the char * from an int value conversion.
*/

static int		log_error(int arg1, char *exp, char *res)
{
	ERROR_LOG
	printf("file %s.\nArgs : %d (int).\nExpected : %s (char *).\nGot :\
 %s (char *).\n",
		   __FILE__, arg1, exp, res);
	return (0);
}

static int		test_case(char *arg1)
{
	char	*res;
	char 	*exp;
	pid_t	pid;
	int		status;
	
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
			printf(" - Case : %d ", atoi(arg1));
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res = ft_itoa(atoi(arg1));
		exp = strdup(arg1);
		if (strcmp(res, exp) == 0)
		{
			free(exp);
			exit(EXIT_SUCCESS);
		}
		log_error(atoi(arg1), exp, res);
		free(exp);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_itoa(void)
{
	char	*cases[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
						"-1", "-10", "-2147483648", "2147483647", NULL};
	int		i;

	i = 0;
	NAME_LOG("ft_itoa()")
	while (cases[i] != NULL)
	{
		if (test_case(cases[i]) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
