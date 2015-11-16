/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:21:29 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/26 14:58:17 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "test.h"

static void		indent(int n)
{
	int		i;

	i = 0;
	while (i < n * 4)
	{
		log_char(' ');
		i++;
	}
}

static void		log_lst_bis(t_list *lst, int n)
{
	char	*content;

	indent(n);
	if (lst != NULL)
	{
		printf("Address : %x\n", lst);
		indent(n);
		printf("index : %d.\n", n);
		indent(n);
		printf("Content size : %d (size_t)", (*lst).content_size);
		indent(n);
		content = strndup((*lst).content, (*lst).content_size);
		printf("Content : %s (void * casted into a char *).\n",
			   content == NULL ? "NULL" : content);
		if (content)
			free(content);
		indent(n);
		printf("NEXT : \n");
		log_lst_bis((*lst).next, n + 1);
	}
	else
	{
		printf("NULL.\n");
	}
}

void			log_lst(t_list *lst)
{
	log_lst_bis(lst, 0);
}
