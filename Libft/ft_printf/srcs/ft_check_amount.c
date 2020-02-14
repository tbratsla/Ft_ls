/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_amount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:00:23 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/08 13:00:24 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	copy_param(const char *format, t_split *s, char **pos)
{
	s->j = s->chr;
	while (format[s->j])
	{
		if ((ft_isalpha(format[s->j]) && format[s->j] != 'l' &&\
			format[s->j] != 'h' && format[s->j] != 'L') || format[s->j] == '%')
		{
			pos[s->i] = ft_strnew(s->j - s->chr + 1);
			ft_strncpy(pos[s->i], &format[s->chr], s->j - s->chr + 1);
			s->i++;
			break ;
		}
		s->j++;
	}
}

char	**ft_make_pos(const char *format, int *amount)
{
	t_split	s;
	char	**pos;

	pos = ft_memalloc(sizeof(char *) * *amount);
	s.chr = 0;
	s.i = 0;
	while ((s.chr = ft_strchr(&format[s.chr], '%') - format + 1) > 0
		&& s.chr < (int)ft_strlen(format))
	{
		if (format[s.chr] == '%')
			s.chr++;
		else
		{
			copy_param(format, &s, pos);
			if (!format[s.j])
			{
				(*amount) -= s.i;
				if (pos)
					return (pos);
				return (NULL);
			}
			s.chr = s.j;
		}
	}
	return (pos);
}

void	free_pos(char **pos, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		free(pos[i]);
		i++;
	}
	free(pos);
}
