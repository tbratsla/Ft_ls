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
# include <termios.h>
# include <sys/ioctl.h>

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
	struct stat			get_stat;
	int					num;
	int					info;
	char				*direct_name;
	int					type;
	int					leng;
	struct s_files		*next;
}						t_files;

typedef	struct			s_dir
{
	int					count;
	int					vis_count;
	int					max_len;
	char				*filename;
	t_files				*files;
	struct s_dir		*next;
}						t_dir;

typedef struct			s_ls 
{
	struct winsize		win;
	char				*str;
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

/*
**	Debug functions
*/

void					print_direct(t_dir *direct);

/*
**	Output functions
*/

void					print_file(t_files *file, t_ls *ft_ls, int max_len, int count);
void					print_l(t_files *file, t_ls *ft_ls, int count);

/*
**	Sort functions
*/

t_files					*sort_alp_file(t_files *file);
t_files					*sort_rev_alp_file(t_files *file);
t_files					*sort_time_file(t_files *file, unsigned char flag);
void					svap_file(t_files *file1, t_files *file2);

/*
** Free functions
*/

void					free_double_str(char **str, int count);
void					free_direct(t_dir *direct);
void					ft_free_files(t_files *file);

/*
** Math function
*/

int						max_div(int a, int b);
int						count_str_len(int max_len);
int						count_word_in_str(t_ls *ft_ls, int max_len, int count);
char					**get_double_str(t_files *file, int count);

#endif
