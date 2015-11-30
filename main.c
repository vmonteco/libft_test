/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 04:22:52 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/30 05:11:27 by vmonteco         ###   ########.fr       */
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
#define TEST_LSTMAP
#define DEP

int		main(void)
{
#ifdef TEST_ATOI	
# ifdef DEP
# endif
	test_atoi();
#endif
#ifdef TEST_ABSOLUTE
# ifdef DEP
# endif
	test_absolute();
#endif
#ifdef TEST_BZERO
# ifdef DEP
# endif
	test_bzero();
#endif
#ifdef TEST_ISALNUM
# ifdef DEP
# endif
	test_isalnum();
#endif
#ifdef TEST_ISALPHA
# ifdef DEP
# endif
	test_isalpha();
#endif
#ifdef TEST_ISASCII
# ifdef DEP
# endif
	test_isascii();
#endif
#ifdef TEST_ISDIGIT
# ifdef DEP
# endif
	test_isdigit();
#endif
#ifdef TEST_ISLOWER
# ifdef DEP
# endif
	test_islower();
#endif
#ifdef TEST_ISPRINT
# ifdef DEP
# endif
	test_isprint();
#endif
#ifdef TEST_ISUPPER
# ifdef DEP
# endif
	test_isupper();
#endif
#ifdef TEST_ITOA
# ifdef DEP
# endif
	test_itoa();
#endif
#ifdef TEST_LSTNEW
# ifdef DEP
# endif
	test_lstnew();
#endif
#ifdef TEST_LSTADD
# ifdef DEP
	printf("/!\\ ft_lstadd() requires ft_lstnew(). /!\\\n");
# endif
	test_lstadd();
#endif
#ifdef TEST_LSTDELONE
# ifdef DEP
# endif
	test_lstdelone();
#endif
#ifdef TEST_LSTDEL
# ifdef DEP
	printf("/!\\ ft_lstdel() requires ft_lstdelone.  /!\\\n");
# endif
	test_lstdel();
#endif
#ifdef TEST_LSTMAP
# ifdef DEP
	printf("/!\\ ft_lstmap() requires ft_memalloc(). /!\\\n");
# endif
	test_lstmap();
#endif
#ifdef TEST_LSTITER
# ifdef DEP
# endif
	test_lstmap();
#endif
	return (0);
}
