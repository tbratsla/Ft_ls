/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:20:59 by tbratsla          #+#    #+#             */
/*   Updated: 2020/01/29 17:20:59 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_dir	*add_new_direct(t_dir *direct, t_files *file)
{
	t_dir	*start;
	t_dir	*next;
	char	*tmp;
 
	start = direct;
	next = start->next;
	while (file)
	{
		if (file->direct_name[0] == '.')
		{
			file = file->next;
			continue ;
		}
		start->next = ft_memalloc(sizeof(t_dir));
		start = start->next;
		start->filename = ft_strjoin(direct->filename, "/");
		tmp = start->filename;
		start->filename = ft_strjoin(tmp, file->direct_name);
		ft_strdel(&tmp);
		file = file->next;
	}
	start->next = next;
	return (direct);
}

void	set_file_params(t_files *files, struct dirent *entry, t_dir *direct)
{
	files->info = entry->d_ino;
	files->direct_name = ft_strdup(entry->d_name);
	files->type = entry->d_type;
	files->leng = entry->d_reclen;
	files->next = NULL;
	stat(direct->filename, &files->get_stat);
}

t_files		*add_new_file(t_files *files, struct dirent *entry, t_dir *direct)
{
	t_files *start;

	if (!files)
	{
		files = (t_files *)ft_memalloc(sizeof(t_files));
		set_file_params(files, entry, direct);
		return (files);
	}
	else
	{
		start = files;
		while (files->next)
			files = files->next;
		files->next = (t_files *)ft_memalloc(sizeof(t_files));
		files = files->next;
		set_file_params(files, entry, direct);
		files = start;
		return (files);
	}
	return (files);
}

void	read_by_filename(t_ls *ft_ls)
{
	DIR				*dir;
	struct dirent	*entry;
	t_dir			*direct;
	t_files			*file;

	direct = ft_ls->dir;
	while (direct)
	{
		dir = opendir(direct->filename);
		if (!dir)
		{
			direct = direct->next;
			continue ;
		}
		file = direct->files;
		while ((entry = readdir(dir)) != NULL)
			file = add_new_file(file, entry, direct);
		if (ft_ls->flags.t_f.r == 1)
			file = sort_rev_alp_file(file);
		else if (ft_ls->flags.t_f.t == 1)
			file = sort_time_file(file);
		else
			file = sort_alp_file(file);
		if (ft_ls->flags.t_f.big_r == 1)
			direct = add_new_direct(direct, file);
		print_file(file, ft_ls->flags.t_f.a);
		closedir(dir);
		direct = direct->next;
	}
}

t_ls	*init(void)
{
	t_ls *ft_ls;

	ft_ls = ft_memalloc(sizeof(t_ls));
	return (ft_ls);
}

int		main(int ac, char **av)
{
	t_ls *ft_ls;

	ft_ls = init();

	parsing_arg(ft_ls, ac, av);
	read_by_filename(ft_ls);
	// system("leaks -q ft_ls");
	return (0);
}
