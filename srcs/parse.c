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

t_files *get_filename(t_files *files, char *av)
{
	t_files  *start;

	if (!files)
	{
		files = ft_memalloc(sizeof(t_files));
		(files)->filename = ft_strdup(av);
		(files)->next = NULL;
	}
	else
	{
		start = files;
		while (files)
			files = (files)->next;
		files = ft_memalloc(sizeof(t_files));
		(files)->filename = ft_strdup(av);
		(files)->next = NULL;
		files = start;
		return (start);
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
			ft_ls->dir->files = get_filename(ft_ls->dir->files, av[i]);
		}
		i++;
	}
}
