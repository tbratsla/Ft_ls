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

t_dir	*add_new_direct(t_dir *direct, t_files *file, t_ls *ft_ls)
{
	t_dir	*start;
	t_dir	*next;
	char	*tmp;
 
	start = direct;
	next = start->next;
	while (file)
	{
		if (!ft_strcmp(file->direct_name, ".") || !ft_strcmp(file->direct_name, ".."))
		{
			file = file->next;
			continue ;
		}
		if (ft_ls->flags.t_f.a == 0 && file->direct_name[0] == '.')
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
	char	*tmp;
	char	*tmp1;

	files->info = entry->d_ino;
	files->direct_name = ft_strdup(entry->d_name);
	files->type = entry->d_type;
	files->leng = entry->d_reclen;
	files->next = NULL;
	direct = (void *)direct;
	tmp = ft_strjoin(direct->filename, "/");
	tmp1 = ft_strjoin(tmp, files->direct_name);
	stat(tmp1, &files->get_stat);
	free(tmp);
	free(tmp1);
	if (direct->max_len < (int)ft_strlen(files->direct_name))
		direct->max_len = ft_strlen(files->direct_name);
}

t_files		*add_new_file(t_files *files, struct dirent *entry, t_dir *direct)
{
	t_files *start;
	int		i;

	if (!files)
	{
		direct->count = 0;
		direct->vis_count = 0;
		files = (t_files *)ft_memalloc(sizeof(t_files));
		files->num = 0;
		set_file_params(files, entry, direct);
		return (files);
	}
	else
	{
		start = files;
		direct->count++;
		if (entry->d_name[0] != '.')
			direct->vis_count++;
		while (files->next)
			files = files->next;
		i = files->num + 1;
		files->next = (t_files *)ft_memalloc(sizeof(t_files));
		files = files->next;
		set_file_params(files, entry, direct);
		files->num = i;
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
			direct = add_new_direct(direct, file, ft_ls);
		if (ft_ls->flags.t_f.big_r == 1 && ft_strcmp(direct->filename, "."))
			ft_printf("\n%s:\n", direct->filename);
		if (ft_ls->flags.t_f.l == 0)
			print_file(file, ft_ls, direct->max_len,\
				ft_ls->flags.t_f.a == 1 ? direct->count : direct->vis_count);
		else
			print_l(file, ft_ls,\
				ft_ls->flags.t_f.a == 1 ? direct->count : direct->vis_count);
		closedir(dir);
		direct = direct->next;
	}
}

t_ls	*init(void)
{
	t_ls *ft_ls;

	ft_ls = ft_memalloc(sizeof(t_ls));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ft_ls->win);
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
