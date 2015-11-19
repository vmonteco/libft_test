/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:03:07 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 13:03:31 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"
#include "test.h"

/*
** This function should check if the int value is the one of an ascii char.
*/

static int		log(char *arg1, int exp, int res)
{
	printf("ERROR: file %s.\nArgs : %d (int) (='%c').\nExpected : %d (int) (='%\
c').\nGot : %d (int) (='%c').",
		   __file__, arg1, arg1, exp, exp, res, res);
	return (0);
}

static int		test_case(char *arg1, int exp)
{
	int		res;
	int		exp;

	res = ft_isascii(arg1);
	exp = isascii(arg1);
	if (res == exp)
		return (1);
	log(arg1, exp, res);
	return (0);
}

int			test_isascii(void)
{
	if (test_case(' '))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}
