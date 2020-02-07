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
	int			info;
	int			leng;
	int			type;
	char		*name;
	struct stat	stat;

	info = file1->info;
	leng = file1->leng;
	type = file1->type;
	name = file1->direct_name;
	stat = file1->get_stat;
	file1->info = file2->info;
	file1->leng = file2->leng;
	file1->type = file2->type;
	file1->direct_name = file2->direct_name;
	file1->get_stat = file2->get_stat;
	file2->info = info;
	file2->leng = leng;
	file2->type = type;
	file2->direct_name = name;
	file2->get_stat = stat;
}

t_files	*sort_rev_alp_file(t_files *file)
{
	t_files *start;

	start = file;
	while (file->next)
	{
		if (ft_strcmp(file->direct_name, file->next->direct_name) < 0)
		{
			svap_file(file, file->next);
			file = start;
		}
		else
			file = file->next;
	}
	file = start;
	return (file);
}

t_files	*sort_alp_file(t_files *file)
{
	t_files *start;

	start = file;
	while (file->next)
	{
		if (ft_strcmp(file->direct_name, file->next->direct_name) > 0)
		{
			svap_file(file, file->next);
			file = start;
		}
		else
			file = file->next;
	}
	file = start;
	return (file);
}

t_files *sort_time_file(t_files *file)
{
	t_files *start;

	start = file;
	while (file->next)
	{
		ft_printf("%i %lld\n", file->get_stat.st_ctime, file->next->get_stat.st_ctime);
		if (file->get_stat.st_mtime < file->next->get_stat.st_mtime)
		{
			svap_file(file, file->next);
			file = start;
		}
		else
			file = file->next;
	}
	file = start;
	return (file);
}
