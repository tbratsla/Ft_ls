/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:06:54 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/08 15:06:55 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_p(va_list args, char *pos)
{
	char			*before;
	char			*s;
	long long		d;

	d = (long long)va_arg(args, void*);
	if (d == 0)
		s = ft_strdup("0x0");
	else
	{
		s = ft_itoa_base((unsigned long long)d, 16);
		ft_strdown(s);
		before = s;
		s = ft_strjoin("0x", before);
		free(before);
	}
	s = ft_check_pdot(pos, s, d);
	s = ft_check_pminus(pos, s, 0);
	s = ft_str_with_pdigits(pos, s);
	d = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (d);
}

char	*ft_check_pdot(char *pos, char *s, long long d)
{
	char	*help;
	char	*chr;
	int		prec;

	if ((chr = ft_strchr(pos, '.')))
	{
		prec = ft_atoi(&chr[1]);
		prec = prec <= 0 ? 0 : prec + 2;
		if (prec == 0 && d == 0)
		{
			free(s);
			return (ft_strdup("0x"));
		}
		while ((size_t)prec > ft_strlen(s))
		{
			help = s;
			s = ft_strpjoin(help, "0", 2);
			free(help);
		}
	}
	return (s);
}

char	*ft_str_with_pdigits(char *pos, char *s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_digit(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i]);
		while ((size_t)prec > ft_strlen(s))
		{
			help = s;
			s = ft_strjoin(" ", help);
			free(help);
		}
	}
	return (s);
}

char	*ft_check_pminus(char *pos, char *s, int i)
{
	char	*help;
	int		prec;

	prec = (int)ft_strlen(s);
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
		while ((size_t)prec > ft_strlen(s))
		{
			help = s;
			s = ft_strjoin(help, " ");
			free(help);
		}
	}
	return (s);
}
