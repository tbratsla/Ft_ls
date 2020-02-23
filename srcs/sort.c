/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:22:57 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/06 15:22:58 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	svap_file(t_files *file1, t_files *file2)
{
	t_data *tmp;

	tmp = file1->data;
	file1->data = file2->data;
	file2->data = tmp;
}

char	**sort_av(int ac, char **av, unsigned char flag)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		if ((i + 1 < ac && ft_strcmp(av[i], av[i + 1]) > 0 && flag == 0)
			|| (i + 1 < ac && ft_strcmp(av[i], av[i + 1]) < 0 && flag == 1))
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = 1;
		}
			i++;
	}
	return (av);
}

// void	sort_rev_file(t_files **begin)
// {
// 	t_files	*tmp_path;
// 	t_files	*tmp_prev;
// 	t_files	*tmp_next;

// 	tmp_path = *begin;
// 	tmp_prev = NULL;
// 	tmp_next = NULL;
// 	while (tmp_path)
// 	{
// 		tmp_next = tmp_path->next;
// 		tmp_path->next = tmp_prev;
// 		tmp_prev = tmp_path;
// 		tmp_path = tmp_next;
// 	}
// 	*begin = tmp_prev;
// }

t_files	*sort_alp_file(t_files *file, t_ls *ft_ls, t_dir *direct)
{
	t_files *start;
	int		i;
	int		j;

	start = file;
	i = 0;
	while (i < direct->count)
	{
		j = 0;
		while (file->next)
		{
			if ((ft_strcmp(file->data->direct_name,\
				file->next->data->direct_name) > 0\
				 && ft_ls->flags.t_f.r == 0) || (ft_strcmp(file->data->direct_name,\
				file->next->data->direct_name) < 0 &&\
				ft_ls->flags.t_f.r == 1))
			{
				svap_file(file, file->next);
				j++;
			}
			file = file->next;
		}
		if (j == 0)
			break ;
		file = start;
		i++;
	}
	file = start;
	return (file);
}

t_files	*sort_time_file(t_files *file, t_ls *ft_ls, t_dir *direct)
{
	t_files *start;
	t_time	time;
	int		i;

	ft_ls = (void *)ft_ls;
	start = file;
	i = 0;
	while (i < direct->count)
	{
		while (file->next)
		{
			time.time1 = ft_ls->flags.t_f.u == 1 ?\
		file->data->get_lstat.st_atime : file->data->get_lstat.st_mtime;
			time.time2 = ft_ls->flags.t_f.u == 1 ?\
		file->next->data->get_lstat.st_atime :\
		file->next->data->get_lstat.st_mtime;
			if ((time.time1 < time.time2 && ft_ls->flags.t_f.r == 0)
				|| (time.time1 > time.time2 && ft_ls->flags.t_f.r == 1))
				svap_file(file, file->next);
			file = file->next;
		}
		file = start;
		i++;
	}
	file = start;
	return (file);
}
