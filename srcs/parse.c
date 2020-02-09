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

void	check_file(char *av)
{
	DIR		*dir;
	char	*tmp;

	dir = opendir(av);
	if (!dir)
	{
		tmp = ft_strjoin("ft_ls: ", av);
		perror(tmp);
		free(tmp);
		exit(1);
	}
	closedir(dir);
}

t_dir		*get_filename(t_dir *files, char *av)
{
	t_dir	*start;

	check_file(av);
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
	int i;

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
			ft_ls->dir = get_filename(ft_ls->dir, av[i]);
		}
		i++;
	}
	if (!ft_ls->dir)
	{
		ft_ls->dir = ft_memalloc(sizeof(t_dir));
		ft_ls->dir->filename = ft_strdup(".");
	}
}
