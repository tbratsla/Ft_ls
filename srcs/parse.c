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
	if (!dir && ft_strcmp(av, "*"))
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

void	set_arg_flag(t_ls *ft_ls, char *av, int i)
{
	if (av[i] == 'l')
		ft_ls->flags.t_f.l = 1;
	else if (av[i] == 'r')
		ft_ls->flags.t_f.r = ft_ls->flags.t_f.f ? 0 : 1;
	else if (av[i] == 'R')
		ft_ls->flags.t_f.big_r = 1;
	else if (av[i] == 'a')
		ft_ls->flags.t_f.a = 1;
	else if (av[i] == 't')
	{
		ft_ls->flags.t_f.t = ft_ls->flags.t_f.f ? 0 : 1;
	}
	else if (av[i] == 'u')
		ft_ls->flags.t_f.u = 1;
	else if (av[i] == 'f')
	{
		ft_ls->flags.t_f.f = 1;
		ft_ls->flags.t_f.a = 1;
		ft_ls->flags.t_f.t = 0;
		ft_ls->flags.t_f.r = 0;
	}
	else if (av[i] == 'g')
	{
		ft_ls->flags.t_f.g = 1;
		ft_ls->flags.t_f.l = 1;
	}
	else if (av[i] == 'o')
	{
		ft_ls->flags.t_f.o = 1;
		ft_ls->flags.t_f.l = 1;
	}
	else
	{
		print_error(3, &av[i], ft_ls);
		print_error(1, NULL, ft_ls);
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

void	parsing_result(t_ls *ft_ls, t_dir *direct)
{
	if (direct)
	{
		ft_ls->flags.t_f.input = 1;
		sort_and_print_files(ft_ls, direct, direct->files);
		free_direct(direct);
		ft_ls->flags.t_f.print = 1;
		ft_ls->flags.t_f.input = 0;
	}
	else if ((!direct && ft_ls->dir &&\
		ft_ls->dir->next) || ft_ls->flags.t_f.print == 1)
	{
		if (!ft_ls->dir)
			exit(0);
		ft_printf("%s:\n", ft_ls->dir->filename);
	}
	else if (!ft_ls->dir)
	{
		ft_ls->dir = ft_memalloc(sizeof(t_dir));
		ft_ls->dir->filename = ft_strdup(".");
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
			print_error(1, NULL, ft_ls);
		else if (!ft_strcmp("-", av[i]))
			print_error(2, av[i], ft_ls);
		else
		{
			if (ft_ls->flags.t_f.f == 0)
				av = sort_av(ac, av, ft_ls->flags.t_f.r);
			ft_ls->flags.t_f.file = 1;
			ft_ls->dir = get_filename(ft_ls->dir, av[i], &direct, ft_ls);
		}
		i++;
	}
	parsing_result(ft_ls, direct);
}
