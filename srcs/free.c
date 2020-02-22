/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:24:19 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/10 15:24:20 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	free_double_str(char **str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_memdel((void **)&str[i]);
		i++;
	}
	ft_memdel((void **)str);
}

void	ft_free_files(t_files *file)
{
	t_files *next;

	next = NULL;
	while (file)
	{
		next = file->next;
		ft_memdel((void **)&file->data->direct_name);
		ft_memdel((void **)&file->data->user_name);
		ft_memdel((void **)&file->data->group_name);
		ft_memdel((void **)&file);
		file = next;
	}
}

void	free_direct(t_dir *direct)
{
	t_dir	*next;

	next = NULL;
	while (direct)
	{
		ft_free_files(direct->files);
		next = direct->next;
		ft_memdel((void **)&direct->filename);
		ft_memdel((void **)&direct);
		direct = next;
	}
}
