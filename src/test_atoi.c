/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:00:22 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/19 18:51:07 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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

	res = ft_atoi(arg1);
	exp = atoi(arg1);
	if (res == exp)
		return (1);
	log_error(arg1, exp, res);
	return (0);
}

int			test_atoi(void)
{
	int		result;

	NAME_LOG("ft_atoi()")
	result = 1;
	if (test_case("0") == 1)
	{
		SUCCESS_LOG
		return (1);
	}
	return (0);
}
