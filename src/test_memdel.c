/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/06 17:18:29 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		test_case(size_t size)
{
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
		if (WIFSIGNALED(status))
		{
			printf(" - Case : size == %d ", (int)size);
			if (WTERMSIG(status) == SIGSEGV)
				SEGFAULT_ERROR
			else
				printf("OTHER PROBLEM.\n");
		}
	}
	else if (pid == 0)
	{
		res = ft_memalloc(size);
		ft_memdel(&res);
		if (res == NULL)
			exit(EXIT_SUCCESS);
		printf("Result isn't NULL after ft_memdel() call.\n");
		free(res);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_memdel(void)
{
	size_t	cases[] = {0, 1, 10};
	int		i;

	i = 0;
	NAME_LOG("ft_memdel()")
	while ((unsigned long)i < sizeof(cases) / sizeof(size_t))
	{
		if (test_case(cases[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
