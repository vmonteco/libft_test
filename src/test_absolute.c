/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_absolute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:12:05 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 11:11:28 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

/*
** This function should return the absolute value of a int passed as an arg.
*/

static int		log(int arg1, int exp, int res)
{
	printf("ERROR: file %s.\nArgs : %d (int).\nExpected : %d (int).\nGot : %d.",
		   __file__, arg1, exp, res);
	return (0);
}

static int		test_case(int arg1, int exp)
{
	int		res;

	res = ft_absolute(arg1);
	if (res == exp)
		return (1);
	log(arg1, exp, res);
	return (0);
}

int				test_absolute(void)
{
	if (test_case(1, 1) &&
		test_case(-1, 1) &&
		test_case(0, 0))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}
