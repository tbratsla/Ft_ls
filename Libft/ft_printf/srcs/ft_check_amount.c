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

char	**ft_make_pos(const char *format, int *amount)
{
	int		i[3];
	char	**pos;
	int		chr;

	pos = ft_memalloc(sizeof(char *) * *amount);
	chr = 0;
	i[1] = 0;
	while ((chr = ft_strchr(&format[chr], '%') - format + 1) > 0)
		if (format[chr] == '%')
			chr++;
		else
		{
			i[2] = chr;
			while (format[i[2]])
			{
				if ((ft_isalpha(format[i[2]]) && format[i[2]] != 'l' &&
			format[i[2]] != 'h' && format[i[2]] != 'L') || format[i[2]] == '%')
				{
					pos[i[1]] = ft_strnew(i[2] - chr + 1);
					ft_strncpy(pos[i[1]], &format[chr], i[2] - chr + 1);
					i[1]++;
					break ;
				}
				i[2]++;
			}
			if (!format[i[2]])
			{
				(*amount) -= i[1];
				if (pos)
					return (pos);
				else
					return (NULL);
			}
			chr = i[2];
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
