/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:11:39 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/27 12:11:41 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_per(char *pos)
{
	int		i;
	char	*s;

	s = ft_strnew(2);
	s[0] = '%';
	s = ft_str_with_perzero(pos, &s);
	i = 0;
	s = ft_check_perminus(pos, &s, i);
	s = ft_str_with_perdigits(pos, &s);
	i = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (i);
}

char	*ft_str_with_perzero(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i + 1]);
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin("0", help);
			free(help);
		}
	}
	return (*s);
}

char	*ft_str_with_perdigits(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_digit(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i]);
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin(" ", help);
			free(help);
		}
	}
	return (*s);
}

char	*ft_check_perminus(char *pos, char **s, int i)
{
	char	*help;
	int		prec;

	prec = (int)ft_strlen(*s);
	if ((ft_strchr(pos, '-')))
	{
		while (pos[i])
		{
			if (pos[i] >= '1' && pos[i] <= '9')
			{
				prec = ft_atoi(&pos[i]);
				break ;
			}
			if (pos[i] == '.')
				break ;
			i++;
		}
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin(help, " ");
			free(help);
		}
	}
	return (*s);
}
