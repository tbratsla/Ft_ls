/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:19:43 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/06 15:19:43 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_direct(t_dir *direct)
{
	t_dir *begin;

	begin = direct;
	while (begin)
	{
		ft_printf("%s\n", begin->filename);
		begin = begin->next;
	}
}

void	print_file(t_files *file, unsigned char flag)
{
	t_files *begin;

	begin = file;
	while (file)
	{
		if ((file->direct_name[0] == '.' && flag == 1) || file->direct_name[0] != '.')
			ft_printf("%s\n", file->direct_name);
		file = file->next;
	}
	file = begin;
}
