/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 10:19:12 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/17 04:53:40 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	log_char(char c)
{
	write(1, &c, 1);
}
