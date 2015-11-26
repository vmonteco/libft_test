/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 10:57:19 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/20 17:22:16 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	ft_putendl(ft_strstr(ft_strdup("toto"), ft_strdup("")));
	ft_putendl(ft_strstr(ft_strdup("toto"), ft_strdup("toto")));
	ft_putendl(ft_strstr(ft_strdup("tototata"), ft_strdup("toto")));
	ft_putendl(ft_strstr(ft_strdup("tatatototata"), ft_strdup("toto")));
	ft_putendl(ft_strstr(ft_strdup("tatatoto"), ft_strdup("toto")));
	return (0);
}
