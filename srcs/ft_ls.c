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

char	*get_short_name(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i > - 1 && str[i] != '/')
		i--;
	if (i == -1)
		return (str);
	return (&str[i + 1]);
}



void	calc_sizes(t_files *file, t_dir *direct)
{
	int	i;
	int	link;
	int	size;
	int len;

	size = file->data->get_lstat.st_size;
	link = file->data->get_lstat.st_nlink;
	len = ft_strlen(file->data->user_name);
	direct->u_name_len = len > direct->u_name_len ? len : direct->u_name_len;
	len = ft_strlen(file->data->group_name);
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
		if (!ft_strcmp(file->data->direct_name, ".") || !ft_strcmp(file->data->direct_name, ".."))
		{
			file = file->next;
			continue ;
		}
		if (ft_ls->flags.t_f.a == 0 && file->data->direct_name[0] == '.')
		{
			file = file->next;
			continue ;
		}
		if (S_ISLNK(file->data->get_lstat.st_mode))
		{
			file = file->next;
			continue ;
		}
		start->next = ft_memalloc(sizeof(t_dir));
		start = start->next;
		if (S_ISDIR(file->data->get_lstat.st_mode))
			start->dir = 1;	
		start->filename = ft_strjoin(direct->filename, "/");
		tmp = start->filename;
		start->filename = ft_strjoin(tmp, file->data->direct_name);
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

	files->data->info = entry->d_ino;
	files->data->direct_name = ft_strdup(entry->d_name);
	files->data->type = entry->d_type;
	files->data->leng = entry->d_reclen;
	files->next = NULL;
	tmp = ft_strjoin(direct->filename, "/");
	tmp1 = ft_strjoin(tmp, files->data->direct_name);
	lstat(tmp1, &files->data->get_lstat);
	files->data->passwd = getpwuid(files->data->get_lstat.st_uid);
	files->data->group = getgrgid(files->data->get_lstat.st_gid);
	if ((files->data->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || files->data->direct_name[0] != '.')
	{
		direct->total += files->data->get_lstat.st_blocks;
	}
	files->data->user_name = ft_strdup(files->data->passwd->pw_name);
	files->data->group_name = ft_strdup(files->data->group->gr_name);
	calc_sizes(files, direct);
	free(tmp);
	free(tmp1);
	if ((files->data->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || files->data->direct_name[0] != '.')
		if (direct->max_len < (int)ft_strlen(files->data->direct_name))
			direct->max_len = ft_strlen(files->data->direct_name);
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
		files->data = ft_memalloc(sizeof(t_data));
		files->data->num = 0;
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
		i = files->data->num + 1;
		files->next = (t_files *)ft_memalloc(sizeof(t_files));
		files = files->next;
		files->data = ft_memalloc(sizeof(t_data));
		set_file_params(files, entry, direct, ft_ls);
		files->data->num = i;
		files->next = NULL;
		files = start;
		return (files);
	}
	return (files);
}

void	sort_files(t_ls *ft_ls, t_files *file)
{
	if (ft_ls->flags.t_f.t == 1)
		file = sort_time_file(file);
	else
		file = sort_alp_file(file);
	if (ft_ls->flags.t_f.r == 1)
		file = sort_rev_file(&file);
}

void	sort_and_print_files(t_ls *ft_ls, t_dir *direct, t_files *file)
{
	sort_files(ft_ls, file);
	if (ft_ls->flags.t_f.big_r == 1)
		direct = add_new_direct(direct, file, ft_ls);
	if ((ft_ls->flags.t_f.big_r == 1 && ft_strcmp(direct->filename, ".")) || ft_ls->flags.t_f.print == 1)
		ft_printf("\n%s:\n", direct->filename);
	if (ft_ls->flags.t_f.l == 0)
		print_file(file, ft_ls, direct->max_len,\
		ft_ls->flags.t_f.a == 1 ? direct->count : direct->vis_count);
	else
		print_l(file, ft_ls,\
		ft_ls->flags.t_f.a == 1 ? direct->count : direct->vis_count, direct);
}

void	read_by_filename(t_ls *ft_ls)
{
	DIR				*dir;
	struct dirent	*entry;
	t_dir			*direct;
	t_files			*file;
	char			*tmp;

	direct = ft_ls->dir;
	while (direct)
	{
		direct->total = 0;
		dir = opendir(direct->filename);
		if (!dir)
		{
			if (direct->dir == 1)
			{
				tmp = get_short_name(direct->filename);
				tmp = ft_strjoin("ft_ls: ", tmp);
				perror(tmp);
				free(tmp);
			}
			direct = direct->next;
			continue ;
		}
		file = direct->files;
		while ((entry = readdir(dir)) != NULL)
			file = add_new_file(file, entry, direct, ft_ls);
		sort_and_print_files(ft_ls, direct, file);
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
	// system("leaks -q ft_ls");
	return (0);
}
