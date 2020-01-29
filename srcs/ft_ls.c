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

void	print_error(int flag, char *message)
{
	if (flag == 1)
		ft_printf("usage: ./ft_ls [-Rlratufgd] [file ...]\n");
	if (flag == 2)
		ft_printf("ft_ls: %s: No such file or directory\n", message);
	if (flag == 3)
		ft_printf("ft_ls: illegal option -- %c\n", *message);
}

void	get_filename(t_ls *ft_ls, char *av)
{
	ft_printf("Filename: %s\n", av);
	ft_ls->flags.t_f.file = 1;
}

void	get_flag(t_ls *ft_ls, char *av)
{
	int i;

	i = 1;
	while (av[i])
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
			get_filename(ft_ls, av[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_ls *ft_ls;

	ft_ls = ft_memalloc(sizeof(t_ls));
	parsing_arg(ft_ls, ac, av);
	return (0);
}
