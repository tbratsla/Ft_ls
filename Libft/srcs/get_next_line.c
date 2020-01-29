/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:59:38 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/14 13:59:38 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_line(int const fd, char *mass, char *stak[fd])
{
	int				ret;
	char			*sup;
	char			*pos;

	while ((pos = ft_strchr(mass, 10)) == NULL \
			&& (ret = read(fd, mass, BUFF_SIZE)) > 0)
	{
		mass[ret] = '\0';
		sup = stak[fd];
		stak[fd] = ft_strjoin(sup, mass);
		ft_strdel(&sup);
	}
	ft_strdel(&mass);
	if (ret == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stak[MAX_FD];
	char			*mass;
	int				ret;
	char			*sup;
	char			*pos;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(mass = ft_strnew(BUFF_SIZE)) ||\
		fd > MAX_FD)
		return (-1);
	if (stak[fd] == NULL)
		stak[fd] = ft_strnew(1);
	if ((ret = ft_check_line(fd, mass, stak)) == -1)
		return (-1);
	if ((pos = ft_strchr(stak[fd], '\n')) != NULL)
	{
		*line = ft_strsub(stak[fd], 0, pos - stak[fd]);
		sup = stak[fd];
		stak[fd] = ft_strdup(pos + 1);
		ft_strdel(&sup);
		return (1);
	}
	*line = ft_strdup(stak[fd]);
	ft_strdel(&stak[fd]);
	return (IS(ft_strlen(*line)));
}
