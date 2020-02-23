/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:43:53 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/22 16:43:55 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	set_input_param(t_files *file, char *av)
{
	file->data->direct_name = ft_strdup(av);
	lstat(av, &file->data->get_lstat);
	file->data->passwd = getpwuid(file->data->get_lstat.st_uid);
	file->data->group = getgrgid(file->data->get_lstat.st_gid);
	file->data->user_name = ft_strdup(file->data->passwd->pw_name);
	file->data->group_name = ft_strdup(file->data->group->gr_name);
}

t_dir	*get_first_direct(char *av, t_ls *ft_ls)
{
	t_dir *direct;

	direct = (t_dir *)ft_memalloc(sizeof(t_dir));
	direct->files = ft_memalloc(sizeof(t_files));
	direct->files->data = ft_memalloc(sizeof(t_data));
	set_input_param(direct->files, av);
	direct->files->data->num = 0;
	direct->count = 0;
	calc_sizes(direct->files, direct, ft_ls);
	direct->max_len = ft_strlen(av);
	direct->filename = NULL;
	direct->next = NULL;
	return (direct);
}

t_dir	*input_to_files(t_dir *direct, char *av, t_ls *ft_ls)
{
	t_files *start;

	if (!direct)
		direct = get_first_direct(av, ft_ls);
	else
	{
		start = direct->files;
		while (start->next)
			start = start->next;
		start->next = (t_files *)ft_memalloc(sizeof(t_files));
		start = start->next;
		start->data = ft_memalloc(sizeof(t_data));
		set_input_param(start, av);
		direct->count++;
		calc_sizes(start, direct, ft_ls);
		if (direct->max_len < (int)ft_strlen(av))
			direct->max_len = ft_strlen(av);
		start->data->num++;
		start->next = NULL;
		return (direct);
	}
	return (direct);
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

t_dir	*get_filename(t_dir *files, char *av, t_dir **direct, t_ls *ft_ls)
{
	int		i;

	if (!(i = check_file(av)) || i == 0)
		exit(0);
	if (i == 1)
		files = input_to_dir(files, av);
	else
		*direct = input_to_files(*direct, av, ft_ls);
	return (files);
}
