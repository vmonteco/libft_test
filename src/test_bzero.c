/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:12:07 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 11:44:23 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "test.h"

/*
** This function should write n zeroed bytes in string s.
*/


static int		log(char *arg1, size_t arg2, char *str1, char *str2)
{
	printf("ERROR: file %s.\nArgs : %s (char *). %d (size_t).\n",
		   __file__, arg1, arg2);
	return (0);
}

static int		test_case(void *arg1, size_t arg2)
{
	char	*str1;
	char	*str2;

	str1 = strdup(arg1);
	str2 = strdup(str1);
	bzero(str1, arg2);
	ft_bzero(str2, arg2);
	if (str1 && str1 && strncmp(str1, str2, strlen(arg1)) == 0)
	{
		free(str1);
		free(str2);
		return (1);
	}
	log(arg1, arg2, str1, str2);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}

int		test_bzero(void)
{
	if (test_case("11111", 0))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}
