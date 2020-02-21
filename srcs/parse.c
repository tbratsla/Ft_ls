/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:42:48 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/02 14:42:50 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		check_file(char *av)
{
	DIR			*dir;
	char		*tmp;
	struct stat	get_stat;

	dir = opendir(av);
	if (!dir)
	{
		if (stat(av, &get_stat) == -1)
		{
			tmp = get_short_name(av);
			tmp = ft_strjoin("ft_ls: ", tmp);
			perror(tmp);
			free(tmp);
			return (0);
		}
		else
			return (2);
	}
	closedir(dir);
	return (1);
}

t_dir	*input_to_files(t_dir *direct, char *av)
{
	t_files *start;

	if (!direct)
	{
		direct = (t_dir *)ft_memalloc(sizeof(t_dir));
		direct->files = ft_memalloc(sizeof(t_files));
		direct->files->data = ft_memalloc(sizeof(t_data));
		direct->files->data->direct_name = ft_strdup(av);
		lstat(av, &direct->files->data->get_lstat);
		direct->files->data->passwd = getpwuid(direct->files->data->get_lstat.st_uid);
		direct->files->data->group = getgrgid(direct->files->data->get_lstat.st_gid);
		direct->files->data->user_name = ft_strdup(direct->files->data->passwd->pw_name);
		direct->files->data->group_name = ft_strdup(direct->files->data->group->gr_name);
		direct->files->data->num = 0;
		direct->count = 0;
		calc_sizes(direct->files, direct);
		direct->max_len = ft_strlen(av);
		direct->filename = NULL;
		direct->next = NULL;
		return (direct);
	}
	else
	{
		start = direct->files;
		while (start->next)
			start = start->next;
		start->next = (t_files *)ft_memalloc(sizeof(t_files));
		start = start->next;
		start->data = ft_memalloc(sizeof(t_data));
		start->data->direct_name = ft_strdup(av);
		lstat(av, &start->data->get_lstat);
		start->data->passwd = getpwuid(start->data->get_lstat.st_uid);
		start->data->group = getgrgid(start->data->get_lstat.st_gid);
		start->data->user_name = ft_strdup(start->data->passwd->pw_name);
		start->data->group_name = ft_strdup(start->data->group->gr_name);
		direct->count++;
		calc_sizes(start, direct);
		if (direct->max_len < (int)ft_strlen(av))
			direct->max_len = ft_strlen(av);
		start->data->num++;
		start->next = NULL;
		return (direct);
	}

}

t_dir	*input_to_dir(t_dir *files, char *av)
{
	t_dir	*start;

	if (!files)
	{
		files = (t_dir *)ft_memalloc(sizeof(t_dir));
		files->max_len = 0;
		files->count = 0;
		files->filename = ft_strdup(av);
		files->next = NULL;
		return (files);
	}
	else
	{
		start = files;
		files->count++;
		while (files->next)
			files = files->next;
		files->next = (t_dir *)ft_memalloc(sizeof(t_dir));
		files->next->filename = ft_strdup(av);
		files = start;
		return (files);
	}
	return (files);
}

t_dir	*get_filename(t_dir *files, char *av, t_dir **direct)
{
	int		i;

	if (!(i = check_file(av)))
		exit(0);
	if (i == 1)
		files = input_to_dir(files, av);
	else
		*direct = input_to_files(*direct, av);

	return (files);
}

void	set_arg_flag(t_ls *ft_ls, char *av, int i)
{
	if (av[i] == 'l')
		ft_ls->flags.t_f.l = 1;
	else if (av[i] == 'r')
		ft_ls->flags.t_f.r = 1;
	else if (av[i] == 'R')
		ft_ls->flags.t_f.big_r = 1;
	else if (av[i] == 'a')
		ft_ls->flags.t_f.a = 1;
	else if (av[i] == 't')
		ft_ls->flags.t_f.t = 1;
	else if (av[i] == 'u')
		ft_ls->flags.t_f.u = 1;
	else if (av[i] == 'f')
		ft_ls->flags.t_f.f = 1;
	else if (av[i] == 'g')
		ft_ls->flags.t_f.g = 1;
	else if (av[i] == 'd')
		ft_ls->flags.t_f.d = 1;
	else
	{
		print_error(3, &av[i]);
		print_error(1, NULL);
		ft_memdel((void **)&ft_ls);
		exit(0);
	}
}

void	get_flag(t_ls *ft_ls, char *av)
{
	int i;

	i = 1;
	while (av[i])
	{
		set_arg_flag(ft_ls, av, i);
		i++;
	}
}

void	parsing_arg(t_ls *ft_ls, int ac, char **av)
{
	int		i;
	t_dir	*direct;

	direct = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_ls->flags.t_f.file == 0 && av[i][1])
			get_flag(ft_ls, av[i]);
		else if (av[i][0] == '-' && ft_ls->flags.t_f.file == 1 && av[i][1])
		{
			print_error(1, NULL);
			ft_memdel((void **)&ft_ls);
			exit(0);
		}
		else if (av[i][0] == '-' && !av[i][1])
			print_error(2, av[i]);
		else
		{
			ft_ls->flags.t_f.file = 1;
			ft_ls->dir = get_filename(ft_ls->dir, av[i], &direct);
		}
		i++;
	}
	if (direct)
	{
		ft_ls->flags.t_f.input = 1;
		sort_and_print_files(ft_ls, direct, direct->files);
		free_direct(direct);
		ft_ls->flags.t_f.print = 1;
		ft_ls->flags.t_f.input = 0;
	}
	else if (!ft_ls->dir)
	{
		ft_ls->dir = ft_memalloc(sizeof(t_dir));
		ft_ls->dir->filename = ft_strdup(".");
	}
}
