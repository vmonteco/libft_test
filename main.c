/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 04:22:52 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/29 22:46:42 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define TEST_ATOI
#define TEST_ABSOLUTE
#define TEST_BZERO
#define TEST_ISALNUM
#define TEST_ISALPHA
#define TEST_ISASCII
#define TEST_ISDIGIT
#define TEST_ISLOWER
#define TEST_ISPRINT
#define TEST_ISUPPER
#define TEST_ITOA
#define TEST_LSTNEW
#define TEST_LSTADD
#define TEST_LSTDELONE
#define TEST_LSTDEL

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
#ifdef TEST_ISALPHA
	test_isalpha();
#endif
#ifdef TEST_ISASCII
	test_isascii();
#endif
#ifdef TEST_ISDIGIT
	test_isdigit();
#endif
#ifdef TEST_ISLOWER
	test_islower();
#endif
#ifdef TEST_ISPRINT
	test_isprint();
#endif
#ifdef TEST_ISUPPER
	test_isupper();
#endif
#ifdef TEST_ITOA
	test_itoa();
#endif
#ifdef TEST_LSTNEW
	test_lstnew();
#endif
#ifdef TEST_LSTADD
	printf("/!\\ ft_lstadd() requires ft_lstnew(). /!\\\n");
	test_lstadd();
#endif
#ifdef TEST_LSTDELONE
	test_lstdelone();
#endif
#ifdef TEST_LSTDEL
	printf("/!\\ ft_lstdel() requires ft_lstdelone.  /!\\\n");
	test_lstdel();
#endif
	return (0);
}
