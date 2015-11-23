/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:00:22 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/23 16:49:41 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "test.h"

/*
** This function should return the int value from a char * conversion.
*/

static int		log_error(char *arg1, int exp, int res)
{
	ERROR_LOG
	printf("file %s.\nArgs : %s (char *).\nExpected : %d (int).\nGot :\
 %d (int).\n",
		   __FILE__, arg1, exp, res);
	return (0);
}

static int		test_case(char *arg1)
 {
	int		res;
	int		exp;
	pid_t	pid;
	int		status;
	
	pid = fork();
	if (pid < 0)
	{
		FORK_ERROR
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf(" - Case : %s ", arg1);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res = ft_atoi(arg1);
		if (arg1 != NULL) // Standard atoi() should segfault in this case.
		{
			exp = atoi(arg1);
			if (res == exp)
				return (1);
		}
		else
			return (1);
		log_error(arg1, exp, res);
	}
	return (0);
}

int			test_atoi(void)
{
	char	*cases[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
						"-1", "-10", "-2147483648", "2147483647", NULL};
	int		i;

	i = 0;
	NAME_LOG("ft_atoi()")
	while (cases[i] != NULL)
	{
		if (test_case(cases[i]) != 1)
			return (0);
		i++;
	}
	if (test_case(NULL) != 1)
		return (0);
	SUCCESS_LOG
	return (1);
}
