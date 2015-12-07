/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/07 18:12:53 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		log_error(void *s, int c, size_t n, void *res1, void *res2)
{
	size_t	i;

	ERROR_LOG
	i = 0;
	printf("file %s.\ns : %s (void *)\nc : %d (int)\nn : %d (size_t)\n\
res1 : %s\nres2 : %s.\nres1 == res2 ? %s\n",
		   __FILE__,
		   s == NULL ? "NULL" : "Not NULL",
		   c,
		   (int) n,
		   res1 == NULL ? "NULL" : "Not NULL",
		   res2 == NULL ? "NULL" : "Not NULL",
		   res1 == res2 ? "Yes" : "No");
	return (0);
}

static int		test_case(void *s, int c, size_t n)
{
	void	*res1;
	void	*res2;
	pid_t	pid;
	int		status;

	pid = fork();
	status = EXIT_FAILURE;
	if (pid < 0)
		FORK_ERROR
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf("file %s.\ns : %s (void *)\nc : %d (int)\nn : %d (size_t)\n.",
				   __FILE__,
				   s == NULL ? "NULL" : "Not NULL",
				   c,
				   (int) n);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		res1 = ft_memchr(s, c, n);
		res2 = memchr(s, c, n);
		if (res1 == res2)
			exit(EXIT_SUCCESS);
		log_error(s, c, n, res1, res2);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_memchr(void)
{
	void	*cases_s[] = {"aaaaa", "aaaaa", "aaaaa", "aaaaa", "aaaaa", "", "", "", NULL};
	int		cases_c[] = {'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
	size_t	cases_n[] = {0, 2, 5, 6, 7, 2, 2, 0, 0};
	int		i;

	i = 0;
	NAME_LOG("ft_memchr()")
	while ((unsigned long)i < sizeof(cases_s) / sizeof(void *))
	{
		if (test_case(cases_s[i], cases_c[i], cases_n[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
