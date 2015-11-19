/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 12:54:26 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 12:56:35 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"
#include "test.h"

/*
** This function should check if the int value is the one of an alnum char.
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

	res = ft_isalnum(arg1);
	exp = isalnum(arg1);
	if (res == exp)
		return (1);
	log(arg1, exp, res);
	return (0);
}

int			test_isalnum(void)
{
	if (test_case(' '))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}

