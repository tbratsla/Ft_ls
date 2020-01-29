/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:00:30 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/25 12:00:31 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_check_fflags(char **s, int neg, char **pos)
{
	int i;

	*s = ft_str_with_fgrid(*pos, s);
	*s = ft_check_fplus(*pos, s, neg);
	*s = ft_str_with_fzero(*pos, s, neg);
	i = 0;
	*s = ft_check_fminus(*pos, s, i);
	*s = ft_str_with_fdigits(*pos, s);
	return (*s);
}

char	*ft_str_with_fzero(char *pos, char **s, int neg)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i + 1]);
		if (!(ft_strchr(pos, '+')) && neg >= 0 && !(ft_strchr(pos, ' ')))
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

char	*ft_str_with_fdigits(char *pos, char **s)
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

char	*ft_check_fminus(char *pos, char **s, int i)
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

char	*ft_check_fplus(char *pos, char **s, int neg)
{
	char	*help;

	if (ft_strchr(pos, '+'))
	{
		help = *s;
		if (neg >= 0)
			*s = ft_strjoin("+", help);
		free(help);
	}
	if ((ft_strchr(pos, ' ')) && !(ft_strchr(pos, '+')))
	{
		if (neg >= 0)
		{
			help = *s;
			*s = ft_strjoin(" ", help);
			free(help);
		}
	}
	return (*s);
}
