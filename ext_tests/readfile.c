/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:10:30 by vmonteco          #+#    #+#             */
/*   Updated: 2015/12/17 13:15:25 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		main(void)
{
	char	*str;

	while (get_next_line(0, &str))
		ft_putendl(str);
	return (0);
}
