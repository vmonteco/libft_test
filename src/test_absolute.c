/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_absolute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:12:05 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 10:54:19 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

/*
** This function should return the absolute value of a int passed as an arg.
*/

static int		log(int arg1, int exp, int res)
{
	log_str("ERROR: file ");
	log_str(__file__);
	log_str(" at line ");
	log_nbr(line);
	log_str("\nArgs : ");
	log_nbr(arg1);
	log_str(" (int).\nExpected : ");
	log_nbr(exp);
	log_str(" (int).\nGot : ");
	log_nbr(res);
	log_str(" (res).");
	return (0);
}

static int		test_case(int arg1, int exp)
{
	int		res;

	res = ft_absolute(arg1);
	if (res == exp)
	{
		return (1);
	}
	log(arg1, exp, res);
	return (0);
}

int				test_absolute()
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
