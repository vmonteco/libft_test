/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:06:47 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 13:13:34 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "test.h"

/*
** This function should return the int value from a char * conversion.
*/

static int		log(int arg1, char *res, char *res)
{
	printf("ERROR: file %s.\nArgs : %d (int).\nExpected : %d (char *).\nGot : %\
d (int).",
		   __file__, arg1, exp, res);
	return (0);
}

static int		test_case(int arg1, char *exp)
{
	char	*res;
	char	*exp;

	res = ft_itoa(arg1);
	exp = itoa(arg1);
	if (res == exp)
		return (1);
	log(arg1, exp, res);
	return (0);
}

int			test_itoa(void)
{
	if (test_case(0, "0"))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}
