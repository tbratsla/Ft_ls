/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:03:42 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/22 18:03:43 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ft_parse_time(time_t t, time_t time)
{
	char *str;
	char *tmp;

	if (t - time < 15778463)
	{
		str = ft_strdup(ctime(&time));
		str[16] = '\0';
	}
	else
	{
		str = ctime(&time);
		tmp = &str[20];
		tmp[4] = '\0';
		str[11] = ' ';
		str[12] = '\0';
		str = ft_strjoin(str, tmp);
	}
	return (str);
}

char	*ft_get_time(t_files *start, t_ls *ft_ls)
{
	time_t	t;
	char	*str;

	t = time(&t);
	if (ft_ls->flags.t_f.u == 1)
		str = ft_parse_time(t, start->data->get_lstat.st_atime);
	else
		str = ft_parse_time(t, start->data->get_lstat.st_mtime);
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

void	ft_get_link(t_dir *direct, t_files *start, char *str)
{
	char		*tmp;
	char		*link;
	static char	buff[512];

	link = ft_strjoin(direct->filename, "/");
	tmp = ft_strjoin(link, start->data->direct_name);
	free(link);
	readlink(tmp, buff, sizeof(buff));
	free(tmp);
	ft_printf(" %s %s -> %s\n", &str[4], start->data->direct_name, buff);
}
