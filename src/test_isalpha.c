/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 05:15:18 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/26 04:43:21 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function checks if the given char is a number or a letter.
*/

static int		log_error(int arg1, int exp, int res)
{
	ERROR_LOG
	printf("file %s.\nArgs : %d (int).\nExpected : %d (int).\nGot :\
 %d (int).\n",
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
		res = ft_isalpha(arg1);
		exp = isalpha(arg1);
#ifdef __linux__
		if (!!res == !!exp)
#endif
#ifdef __APPLE__
		if (res == exp)
#endif
			exit(EXIT_SUCCESS);
		log_error(arg1, exp, res);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_isalpha(void)
{
	int	i;
	int min;
	int max;

#ifdef __linux__
	min = 0;
	max = 255;
#endif
#ifdef __APPLE__
	min = -300;
	max = 300;
#endif
	i = min;
	NAME_LOG("ft_isalpha()")
	while (i < max)
	{
		if (test_case(i) != 1)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
