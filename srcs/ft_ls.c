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

void	calc_sizes(t_files *file, t_dir *direct)
{
	int	i;
	int	link;
	int	size;
	int len;

	size = file->get_stat.st_size;
	link = file->get_stat.st_nlink;
	len = ft_strlen(file->user_name);
	direct->u_name_len = len > direct->u_name_len ? len : direct->u_name_len;
	len = ft_strlen(file->group_name);
	direct->g_name_len = len > direct->g_name_len ? len : direct->g_name_len;
	i = 1;
	while (link /= 10)
		i++;
	direct->link_len = i > direct->link_len ? i : direct->link_len;
	i = 1;
	while (size /= 10)
		i++;
	direct->bite_size_len = i > direct->bite_size_len ? i : direct->bite_size_len;

}

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

void	set_file_params(t_files *files, struct dirent *entry, t_dir *direct, t_ls *ft_ls)
{
	char	*tmp;
	char	*tmp1;

	files->info = entry->d_ino;
	files->direct_name = ft_strdup(entry->d_name);
	files->type = entry->d_type;
	files->leng = entry->d_reclen;
	files->next = NULL;
	tmp = ft_strjoin(direct->filename, "/");
	tmp1 = ft_strjoin(tmp, files->direct_name);
	stat(tmp1, &files->get_stat);
	lstat(tmp1, &files->get_lstat);
	files->passwd = getpwuid(files->get_stat.st_uid);
	files->group = getgrgid(files->get_stat.st_gid);
	if ((files->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || files->direct_name[0] != '.')
	{
		direct->total += files->get_lstat.st_blocks;
	}
	files->user_name = ft_strdup(files->passwd->pw_name);
	files->group_name = ft_strdup(files->group->gr_name);
	calc_sizes(files, direct);
	// acl(tmp1, GETACL, 1, files->aclbufp);
	free(tmp);
	free(tmp1);
	if (direct->max_len < (int)ft_strlen(files->direct_name))
		direct->max_len = ft_strlen(files->direct_name);
}

t_files		*add_new_file(t_files *files, struct dirent *entry, t_dir *direct, t_ls *ft_ls)
{
	t_files *start;
	int		i;

	if (!files)
	{
		direct->count = 0;
		direct->vis_count = 0;
		files = (t_files *)ft_memalloc(sizeof(t_files));
		files->num = 0;
		set_file_params(files, entry, direct, ft_ls);
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
		set_file_params(files, entry, direct, ft_ls);
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
		direct->total = 0;
		dir = opendir(direct->filename);
		if (!dir)
		{
			direct = direct->next;
			continue ;
		}
		file = direct->files;
		while ((entry = readdir(dir)) != NULL)
			file = add_new_file(file, entry, direct, ft_ls);
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
				ft_ls->flags.t_f.a == 1 ? direct->count : direct->vis_count, direct);
		closedir(dir);
		ft_free_files(file);
		direct = direct->next;
	}
	free_direct(ft_ls->dir);
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
	free(ft_ls);
	return (0);
}
