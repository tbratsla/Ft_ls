/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:29:34 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/20 14:29:34 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_c(va_list args, char *pos)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	s = ft_strnew(2);
	j = 0;
	s[0] = (char)va_arg(args, int);
	if ((int)s[0] == 0)
		j++;
	s = ft_str_with_czero(pos, &s);
	i = 0;
	s = ft_check_cminus(pos, &s, i);
	s = ft_str_with_cdigits(pos, &s, j);
	len = ft_strlen(s);
	ifj(&len, &pos, &s, j);
	free(s);
	return (len);
}

char	*ft_str_with_czero(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0  \
		&& !(ft_strchr(pos, '-')))
	{
		if ((*s[0] >= 33 && *s[0] <= 126) || *s[0] == 0)
			prec = ft_atoi(&pos[i + 1]);
		else
			prec = ft_atoi(&pos[i + 1]) + 1;
		if (*s[0] < 33 || *s[0] > 125)
			prec--;
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin("0", help);
			free(help);
		}
	}
	return (*s);
}

char	*ft_str_with_cdigits(char *pos, char **s, int j)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_digit(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i]);
		if (j)
			prec--;
		if (ft_check_zero(pos) < 0)
			while ((size_t)prec > ft_strlen(*s))
			{
				help = *s;
				*s = ft_strjoin(" ", help);
				free(help);
			}
	}
	return (*s);
}

char	*ft_check_cminus(char *pos, char **s, int i)
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
		if (*s[0] < 33 || *s[0] > 125)
			prec--;
		while ((size_t)prec > ft_strlen(*s))
			ADDSP(s, help);
	}
	return (*s);
}

void	ifj(int *len, char **pos, char **s, int j)
{
	if (j)
	{
		if (ft_strchr(*pos, '-'))
		{
			ft_putchar('\0');
			ft_putstr(*s);
		}
		else
		{
			ft_putstr(*s);
			ft_putchar('\0');
		}
		(*len)++;
	}
	else
		ft_putstr(*s);
}
