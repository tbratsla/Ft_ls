/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:05:56 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/28 12:05:56 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_str_with_zero(char *pos, char **s, long long d)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0 && \
		!ft_strchr(pos, '.') && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i + 1]);
		if (!(ft_strchr(pos, '+')) && d >= 0 && !(ft_strchr(pos, ' ')))
			while ((size_t)prec > ft_strlen(*s))
			{
				help = *s;
				*s = ft_strjoin("0", help);
				free(help);
			}
		else
			while ((size_t)prec > ft_strlen(*s))
			{
				help = *s;
				*s = ft_strpjoin(help, "0", 1);
				free(help);
			}
	}
	return (*s);
}

char	*ft_str_with_digits(char *pos, char **s)
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

char	*ft_check_minus(char *pos, char **s, int i)
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

char	*ft_check_plus(char *pos, char **s, long long d)
{
	char	*help;

	if (ft_strchr(pos, '+'))
	{
		if (d >= 0)
		{
			help = *s;
			*s = ft_strjoin("+", help);
			free(help);
		}
	}
	if ((ft_strchr(pos, ' ')) && !(ft_strchr(pos, '+')))
	{
		if (d >= 0)
		{
			help = *s;
			*s = ft_strjoin(" ", help);
			free(help);
		}
	}
	return (*s);
}
