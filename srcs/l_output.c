/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:19:46 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/11 18:19:46 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*create_l_param_str(t_dir *direct)
{
	char *str;
	char *itoa_tmp;
	char *tmp;

	str = ft_strdup(" %");
	itoa_tmp = ft_itoa(direct->link_len);
	tmp = str;
	str = ft_strjoin(tmp, itoa_tmp);
	free(itoa_tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "i %");
	free(tmp);
	itoa_tmp = ft_itoa(direct->u_name_len);
	tmp = str;
	str = ft_strjoin(tmp, itoa_tmp);
	free(itoa_tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "s %");
	free(tmp);
	itoa_tmp = ft_itoa(direct->g_name_len);
	tmp = str;
	str = ft_strjoin(tmp, itoa_tmp);
	free(itoa_tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "s %");
	free(tmp);
	itoa_tmp = ft_itoa(direct->bite_size_len);
	tmp = str;
	str = ft_strjoin(tmp, itoa_tmp);
	free(itoa_tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "i ");
	free(tmp);
	return (str);
}

void	print_permissions(t_files *file)
{
	char	type;

	type = S_ISLNK(file->get_stat.st_mode) ? 'l' : '-';
	type = S_ISDIR(file->get_stat.st_mode) ? 'd' : type;
	type = S_ISCHR(file->get_stat.st_mode) ? 'c' : type;
	type = S_ISBLK(file->get_stat.st_mode) ? 'b' : type;
	ft_printf("%c%c%c%c%c%c%c%c%c%c", type,
	(file->get_stat.st_mode & S_IRUSR) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWUSR) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXUSR) ? 'x' : '-',
	(file->get_stat.st_mode & S_IRGRP) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWGRP) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXGRP) ? 'x' : '-',
	(file->get_stat.st_mode & S_IROTH) ? 'r' : '-',
	(file->get_stat.st_mode & S_IWOTH) ? 'w' : '-',
	(file->get_stat.st_mode & S_IXOTH) ? 'x' : '-');
}

void	print_l(t_files *file, t_ls *ft_ls, int count, t_dir *direct)
{
	t_files *start;
	char	*str;

	start = file;
	count++;
	ft_printf("total %i\n", direct->total);
	while (start)
	{
		if ((start->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || start->direct_name[0] != '.')
		{
			print_permissions(start);
			str = create_l_param_str(direct);
			ft_printf(str, start->get_stat.st_nlink, start->user_name, start->group_name, start->get_stat.st_size);
			ft_printf("%s\n", start->direct_name);
			free(str);
		}
		start = start->next;
	}
}
