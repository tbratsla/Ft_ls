/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_ptint_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:40:52 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/06 11:40:53 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_oflags(char *pos, char **s)
{
	int		i;

	*s = ft_str_with_ogrid(pos, s);
	*s = ft_check_odot(pos, s);
	*s = ft_str_with_ozero(pos, s);
	i = 0;
	*s = ft_check_ominus(pos, s, i);
	*s = ft_str_with_odigits(pos, s);
	i = ft_strlen(*s);
	ft_putstr(*s);
	free(*s);
	return (i);
}

char	*ft_check_odot(char *pos, char **s)
{
	char	*help;
	char	*chr;
	int		prec;

	if ((chr = ft_strchr(pos, '.')))
	{
		prec = ft_atoi(&chr[1]);
		prec = prec < 0 ? 0 : prec;
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin("0", help);
			free(help);
		}
	}
	return (*s);
}

int		ft_check_ozero(char *pos)
{
	int i;

	i = 0;
	while (pos[i])
	{
		if ((pos[i] >= '1' && pos[i] <= '9') || pos[i] == '.')
		{
			return (-1);
		}
		if (pos[i] == '0')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_check_odigit(char *pos)
{
	int i;

	i = 0;
	while (pos[i])
	{
		if (pos[i] == '.')
			return (-1);
		if ((pos[i] >= '1' && pos[i] <= '9'))
			return (i);
		i++;
	}
	return (-1);
}
