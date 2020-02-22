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

char	**sort_av(int ac, char **av)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		if (i + 1 < ac && ft_strcmp(av[i], av[i + 1]) > 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
	return (av);
}

t_files	*sort_rev_file(t_files **alst)
{
	t_files	*prev;
	t_files	*cur;
	t_files	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
	return (*alst);
}

t_files	*sort_alp_file(t_files *file)
{
	t_files *start;
	int		i;

	start = file;
	i = 0;
	while (file->next)
	{
		if (ft_strcmp(file->data->direct_name,\
			file->next->data->direct_name) > 0)
		{
			svap_file(file, file->next);
			file = start;
		}
		else
			file = file->next;
		i++;
	}
	file = start;
	return (file);
}

t_files	*sort_time_file(t_files *file)
{
	t_files *start;
	t_time	time;

	start = file;
	while (file->next)
	{
		time.time1 = file->data->get_lstat.st_mtime;
		time.time2 = file->next->data->get_lstat.st_mtime;
		if (time.time1 < time.time2)
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
