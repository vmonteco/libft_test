/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:44:22 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 10:29:28 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
		ft_putpositive(x);
	}
}