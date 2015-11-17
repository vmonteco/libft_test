/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:44:22 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/17 04:59:15 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	log_positive(int n)
{
	if (n > 0)
	{
		log_positive(n / 10);
		log_char((n % 10) + '0');
	}
}

void	lognbr(int n)
{
	int		x;

	x = n;
	if (x == 0)
		log_char('0');
	else
	{
		if (x < 0)
		{
			log_char('-');
			x = (-x);
		}
		log_positive(x);
	}
}
