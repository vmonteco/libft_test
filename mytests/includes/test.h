/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 10:57:03 by vmonteco          #+#    #+#             */
/*   Updated: 2015/11/17 04:27:15 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdlib.h>

/*
** HEADERS
*/

/*
** MACROS
*/

# define ERROR_LOG {log_str((char *)__func__); log_str(" : \033[32OK!\033[0m");}
# define SUCCESS_LOG {log_str((char *)__func__); log_str(" : \033[31mERROR!\033[0m");}

/*
** TYPEDEFS
*/

typedef	union		u_func
{
	void			(*f1)(void);
	int				(*f2)(int);
}					t_func;

typedef struct		s_arg
{
	void			*content;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_case
{
	t_arg			*args;
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

/*
** STRUCTURES FUNCTIONS
*/

t_arg				*add_arg();

/*
** TOOLS
*/

void				log_str(char *str);
void				log_char(char c);
void				log_str_endl(char *str);

/*
** TEST FUNCTIONS
*/

int					test_atoi(void);

#endif
