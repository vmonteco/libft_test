/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:40:28 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/07 18:08:27 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** This function should write n zeroed bytes to the string the address is
** passed as a argument.
*/

static int		log_error(void *s1, const void *s2, size_t n, void *cpy1, void *cpy2)
{
	size_t	i;

	ERROR_LOG
	i = 0;
	printf("file %s.\ns1 : %s (void *)\ns2 : %s (void *)\nn : %d (size_t)\n\
cpy1 : %s\ncpy2 : %s.\ncpy1 == cpy2 ? %s\n",
		   __FILE__,
		   s1 == NULL ? "NULL" : "Not NULL",
		   s2 == NULL ? "NULL" : "Not NULL",
		   (int) n,
		   cpy1 == NULL ? "NULL" : "Not NULL",
		   cpy2 == NULL ? "NULL" : "Not NULL",
		   memcmp(cpy1, cpy2, n) == 0 ? "Yes" : "No");
	return (0);
}

static int		test_case(void *s1, const void *s2, size_t n)
{
	void	*cpy1;
	void	*cpy2;
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
		if (s1 == NULL && ft_memcpy(NULL, NULL, 0) == NULL)
			exit(EXIT_SUCCESS);
		cpy1 = (void *)strdup((char *)s1);
		cpy2 = (void *)strdup((char *)s1);
		cpy1 = ft_memcpy(cpy1, s2, n);
		cpy2 = memcpy(cpy2, s2, n);
		if (memcmp(cpy1, cpy2, n) == 0)
			exit(EXIT_SUCCESS);
		log_error(s1, s2, n, cpy1, cpy2);
		exit(EXIT_FAILURE);
	}
	return (!status);
}

int			test_memcpy(void)
{
	void	*cases_s1[] = {"aaaaa", "aaaaa", "aaaaa", "aaaaa", "aaaaa", "", "", "", NULL};
	void	*cases_s2[] = {"bbbbb", "bbbbb", "bbbbb", "bbbbb", "bbbbb", "", "bb", "bb", NULL};
	size_t	cases_n[] = {0, 2, 5, 6, 7, 2, 2, 0, 0};
	int		i;

	i = 0;
	NAME_LOG("ft_memcpy()")
	while ((unsigned long)i < sizeof(cases_s1) / sizeof(void *))
	{
		if (test_case(cases_s1[i], cases_s2[i], cases_n[i]) == 0)
			return (0);
		i++;
	}
	SUCCESS_LOG
	return (1);
}
