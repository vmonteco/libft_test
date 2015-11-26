/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_absolute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:40 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/26 03:33:55 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should return the absolute value from an int input.
*/

static int		log_error(int arg1, int exp, int res)
{
	ERROR_LOG
	printf("file %s.\nArgs : %d (int).\nExpected : %d (int).\nGot : %d (int).\n\
",
		   __FILE__, arg1, exp, res);
	return (0);
}

static int		test_case(int arg1)
{
	int		res;
	int		exp;
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
			printf(" - Case : %d ", arg1);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res = ft_absolute(arg1);
		if (arg1 > 0)
			exp = arg1;
		else
			exp = -arg1;
		if (res == exp)
			exit(EXIT_SUCCESS);
		log_error(arg1, exp, res);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_absolute(void)
{
	char	*cases[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
						"-1", "-10", "-2147483648", "2147483647", NULL};
	//char	*cases[] = {"0", NULL};
	int		i;

	i = 0;
	NAME_LOG("ft_absolute()")
	while (cases[i] != NULL)
	{
		if (test_case(atoi(cases[i])) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
