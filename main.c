/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 04:22:52 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/23 17:06:10 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define TEST_ATOI
#define TEST_ABSOLUTE

int		main(void)
{
#ifdef TEST_ATOI	
	test_atoi();
#endif
#ifdef TEST_ABSOLUTE
	test_absolute();
#endif
	return (0);
}
