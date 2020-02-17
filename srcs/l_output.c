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
	str = ft_strjoin(tmp, "s");
	free(tmp);
	return (str);
}

char	*get_bite_param_str(t_dir *direct)
{
	char *tmp;
	char *itoa;
	char *str;

	str = ft_strdup(" %");
	tmp = str;
	itoa = ft_itoa(direct->bite_size_len);
	str = ft_strjoin(tmp, itoa);
	free(tmp);
	free(itoa);
	tmp = str;
	str = ft_strjoin(tmp, "i");
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
			ft_printf(str, start->get_stat.st_nlink, start->user_name, start->group_name);
			ft_strdel(&str);
			if (S_ISBLK(start->get_stat.st_mode) || S_ISCHR(start->get_stat.st_mode))
				ft_printf(" %5u, %3u", major(start->get_stat.st_rdev), minor(start->get_stat.st_rdev));
			else
			{
				str = get_bite_param_str(direct);
				ft_printf(str, start->get_stat.st_size);
				ft_strdel(&str);
			}
			if (ft_ls->flags.t_f.u == 1)
				str = ctime(&start->get_stat.st_atime);
			else
				str = ctime(&start->get_stat.st_mtime);
			str[ft_strlen(str) - 2] = '\0';
			ft_printf("%s %s\n", str, start->direct_name);
			// free(str);
		}
		ft_ls->flags.t_f.n_bite = 0;
		start = start->next;
	}
}
