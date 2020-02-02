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

void	read_by_filename(t_ls *ft_ls)
{
	DIR				*dir;
	struct dirent	*entry;
	t_files			*file;

	file = ft_ls->dir->files;
	while (ft_ls->dir->files)
	{
		ft_printf("Filename1 - %s\n", ft_ls->dir->files->filename);
		dir = opendir(ft_ls->dir->files->filename);
		if (!dir)
		{
			perror("diropen");
			exit(1);
		}
		while ((entry = readdir(dir)) != NULL) 
		{
			ft_printf("%d - %s [%d] %d\n",
				entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
		}
		closedir(dir);
		ft_ls->dir->files = ft_ls->dir->files->next;
		if (!ft_ls->dir->files)
		{
			ft_printf("ne file\n");
		}
	}
}

t_ls	*init(void)
{
	t_ls *ft_ls;

	ft_ls = ft_memalloc(sizeof(t_ls));
	ft_ls->dir = ft_memalloc(sizeof(t_dir));
	ft_ls->dir->files = NULL;
	ft_ls->dir->next = NULL;
	return (ft_ls);
}

int		main(int ac, char **av)
{
	t_ls *ft_ls;

	ft_ls = init();
	parsing_arg(ft_ls, ac, av);
	read_by_filename(ft_ls);
	return (0);
}
