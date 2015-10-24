/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 10:57:03 by vmonteco          #+#    #+#             */
/*   Updated: 2015/10/24 13:04:42 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

/*
** HEADERS
*/

/*
** MACROS
*/

/*
** TYPEDEFS
*/

typedef	union		u_func
{
	void			(*f1)(void);
	int				(*f2)(int);
}					t_func;

typedef struct		s_case
{
	void			*content;
	struct s_case	*next;
	size_t			content_size;
}					t_case;

typedef struct		s_test
{
	const char		*name;
	t_func			*f;
	int				f_type;
	t_case			*cases;
}					t_test;

/*
** PROTOTYPES
*/


#endif
