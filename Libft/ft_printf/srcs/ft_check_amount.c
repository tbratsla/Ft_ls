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

	pos = ft_memalloc(sizeof(char *) * *amount);
	i[0] = 0;
	i[1] = 0;
	while ((i[0] = ft_strchr(&format[i[0]], '%') - format + 1) > 0)
		if (format[i[0]] == '%')
			i[0]++;
		else
		{
			i[2] = i[0];
			while (format[i[2]])
			{
				if ((ft_isalpha(format[i[2]]) && format[i[2]] != 'l' &&
			format[i[2]] != 'h' && format[i[2]] != 'L') || format[i[2]] == '%')
					IFF(pos, i, ft_strncpy(pos[i[1]], &format[i[0]], \
								i[2] - i[0] + 1));
				i[2]++;
			}
			if (!format[i[2]])
				RET(amount, i, pos);
			i[0] = i[2];
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
