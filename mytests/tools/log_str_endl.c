/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_str_endl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 10:22:00 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/25 10:23:58 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	log_str_endl(char *str)
{
	log_str(str);
	log_char('\n');
}
