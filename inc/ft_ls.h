/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:21:19 by tbratsla          #+#    #+#             */
/*   Updated: 2020/01/29 17:21:20 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../Libft/inc/libft.h"
# include "../Libft/ft_printf/inc/printf.h"
# include <sys/types.h>
# include <dirent.h>

typedef	union			s_flags
{
	short				flag;
	struct				s_f
	{
		unsigned char	l		: 1;
		unsigned char	r		: 1;
		unsigned char	big_r	: 1;
		unsigned char	a		: 1;
		unsigned char	t		: 1;
		unsigned char	u		: 1;
		unsigned char	f		: 1;
		unsigned char	g		: 1;
		unsigned char	d		: 1;
		unsigned char	file	: 1;
		unsigned char	any		: 6;
	}					t_f;
}						t_flags;

typedef	struct			s_files
{
	char				*filename;
	struct s_files		*next;
}						t_files;

typedef	struct			s_dir
{
	t_files				*files;
	struct s_dir		*next;
}						t_dir;

typedef struct			s_ls
{
	t_flags				flags;
	t_dir				*dir;
}						t_ls;

/*
**	Error functions
*/

void					print_error(int flag, char *message);

/*
**	Parse functions
*/

void					parsing_arg(t_ls *ft_ls, int ac, char **av);

#endif
