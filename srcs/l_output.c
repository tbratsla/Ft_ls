/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:19:46 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/11 18:19:46 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_permissions(t_files *file)
{
	char	type;

	type = S_ISLNK(file->get_stat.st_mode) ? 'l' : '-';
	type = S_ISDIR(file->get_stat.st_mode) ? 'd' : type;
	type = S_ISCHR(file->get_stat.st_mode) ? 'c' : type;
	type = S_ISBLK(file->get_stat.st_mode) ? 'b' : type;
	ft_printf("%c%c%c%c%c%c%c%c%c%c %s\n", type,
	(file->get_stat.st_mode & S_IRUSR) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWUSR) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXUSR) ? 'x' : '-',
	(file->get_stat.st_mode & S_IRGRP) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWGRP) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXGRP) ? 'x' : '-',
	(file->get_stat.st_mode & S_IROTH) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWOTH) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXOTH) ? 'x' : '-',
	file->direct_name);
}

void	print_l(t_files *file, t_ls *ft_ls, int count)
{
	t_files *start;

	start = file;
	count++;
	while (start)
	{
		if ((start->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || start->direct_name[0] != '.')
			print_permissions(start);
		start = start->next;
	}
}
