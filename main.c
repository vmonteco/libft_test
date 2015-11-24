/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 04:22:52 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/24 05:22:31 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define TEST_ATOI
#define TEST_ABSOLUTE
#define TEST_BZERO
#define TEST_ISALNUM

int		main(void)
{
#ifdef TEST_ATOI	
	test_atoi();
#endif
#ifdef TEST_ABSOLUTE
	test_absolute();
#endif
#ifdef TEST_BZERO
	test_bzero();
#endif
#ifdef TEST_ISALNUM
	test_isalnum();
#endif
	return (0);
}
