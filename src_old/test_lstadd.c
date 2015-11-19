/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:41:07 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/26 14:21:01 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

static int		log(void *arg1, size_t arg2, t_list *exp, t_list *res)
{
	printf("ERROR: file %s.\nArgs : %s (void * casted into char *), %d.\nExpect\
ed : %d (int).\nGot : %d (int).",
		   __file__, arg1 == NULL ? "NULL" : (char*)arg1, arg2,
		   exp == NULL ? "NULL" : exp, exp == NULL ? "NULL" : res);
	if (exp != NULL)
		printf("EXP :\ncontent : %s (void * casted into char *).\ncontent_size \
: %d (size_t).\n\n"
	return (0);
}

static int		test_case(void *arg1, size_t arg2, t_list *exp)
{
	t_list	*res;

	res = ft_lstadd(arg1, arg2);
	if ((res == NULL) == (exp == NULL))
	{
		if (res)
		{
			if ((*res).content_size == arg2
				&& strncmp((*res).content, arg1) == 0)
				return (1);
			log(arg1, exp, res);
			return (0);
		}
		return (1);
	}
	return (0);
}

int			test_lstadd(void)
{
	char	*test1;

	test1 = "test";
	if (test_case((void *)test1, sizeof(test1)))
	{
		SUCCESS_LOG
		return (1);
	}
	ERROR_LOG
	return (0);
}
