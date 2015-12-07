/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/07 18:30:44 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		log_error(void *s1, const void *s2, size_t n)
{
	size_t	i;

	ERROR_LOG
	i = 0;
	printf("file %s.\ns1 : %s (void *)\ns2 : %s (void *)\nn : %d (size_t)\n\
memcmp(s1, s2, n) : %d\nft_memcmp(s1, s2, n) : %d.\n\
ft_memcmp(s1, s2, n) == memcmp(s1, s2, n) ? %s\n",
		   __FILE__,
		   s1 == NULL ? "NULL" : "Not NULL",
		   s2 == NULL ? "NULL" : "Not NULL",
		   (int) n,
		   memcmp(s1, s2, n),
		   ft_memcmp(s1, s2, n),
		   memcmp(s1, s2, n) == ft_memcmp(s1, s2, n) ? "Yes" : "No");
	return (0);
}

static int		test_case(void *s1, const void *s2, size_t n)
{
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
			printf("file %s.\ns1 : %s (void *)\ns2 : %s (void *)\nn : %d (size_t)\n.",
				   __FILE__,
				   s1 == NULL ? "NULL" : "Not NULL",
				   s2 == NULL ? "NULL" : "Not NULL",
				   (int) n);
			SEGFAULT_ERROR
		}
	}
	else if (pid == 0)
	{
		if (memcmp(s1, s2, n) == memcmp(s1, s2, n))
			exit(EXIT_SUCCESS);
		log_error(s1, s2, n);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_memcmp(void)
{
	void	*cases_s1[] = {"aaaaa", "aaaaa", "aaaaa", "aaaaa", "aaaaa", "", "", "", NULL};
	void	*cases_s2[] = {"abbab", "aaabb", "ccbbb", "aaaaa", "", "", "bb", "bb", NULL};
	size_t	cases_n[] = {0, 2, 5, 6, 7, 2, 2, 0, 0};
	int		i;

	i = 0;
	NAME_LOG("ft_memcmp()")
	while ((unsigned long)i < sizeof(cases_s1) / sizeof(void *))
	{
		if (test_case(cases_s1[i], cases_s2[i], cases_n[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
