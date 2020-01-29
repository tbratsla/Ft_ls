/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:55:06 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/31 12:55:06 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_uflags(char *pos, char **s)
{
	int		i;

	*s = ft_check_udot(pos, s);
	*s = ft_str_with_uzero(pos, s);
	i = 0;
	*s = ft_check_uminus(pos, s, i);
	*s = ft_str_with_udigits(pos, s);
	i = ft_strlen(*s);
	ft_putstr(*s);
	free(*s);
	return (i);
}

char	*ft_check_udot(char *pos, char **s)
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

int		ft_check_uzero(char *pos)
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

int		ft_check_udigit(char *pos)
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
