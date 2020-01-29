/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_fi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:55:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/20 09:55:04 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long double	ft_calc_modulo(long double nb, int *size)
{
	long double	modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	return (modulo);
}

void		ft_handle_integer(long double *nb, char **str, \
							int *i, long double modulo)
{
	char		*s;
	int			k;
	long long	j;

	j = (long long)*nb;
	k = 0;
	while (j % 10 == 0 && j != 0)
	{
		k++;
		j /= 10;
	}
	if (j == 0)
		k++;
	s = *str;
	while ((long long int)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / modulo) + 48);
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
	while (k-- > 0)
		s[(*i)++] = '0';
}

char		*ft_handle_decimals(char *str, int *i, \
								long double nb, int precision)
{
	int			j[4];
	long int	tmp;

	INI(j, precision, nb);
	tmp = *i;
	str = handle_if(j, str, &tmp, nb);
	*i = tmp;
	while (j[0]++ < j[3] - 1)
	{
		if ((long int)nb == 0 && nb == 0.0)
			CON(str, i);
		tmp = (long int)nb;
		if (j[0] < j[3] - 1)
			str[(*i)++] = (char)(tmp + 48);
		else if ((long int)((nb - tmp) * 10) <= 4)
			str[(*i)++] = (char)(tmp + 48);
		else if (tmp != 9 && (long int)((nb - tmp) * 10) > 4)
			str[(*i)++] = (char)(tmp + 1 + 48);
		else
			ABCDE(j[1], i, str, handle_else_two(&j[1], str, &j[2]));
		nb = (nb - tmp) * 10;
	}
	(*i)++;
	return (str);
}

int			ft_handle_inf(char **s, long double nb)
{
	*s = NULL;
	if (nb == 1.0 / 0.0)
		ft_putstr("inf");
	else if (nb != nb)
		ft_putstr("nan");
	else if (nb == -1.0 / 0.0)
	{
		ft_putstr("-inf");
		return (4);
	}
	return (3);
}

int			ft_put_float_to_string(long double nb, int precision, char **pos)
{
	int			i;
	int			size;
	char		*str;
	int			neg;
	long double	modulo;

	if ((nb == 1.0 / 0.0) || nb != nb || nb == -1.0 / 0.0)
		return (ft_handle_inf(&str, nb));
	size = 1;
	neg = ((*(((char*)&nb) + 9)) >> 7) ? 1 : 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modulo = ft_calc_modulo(nb, &size);
	size += precision;
	str = ft_strnew(size);
	i = 0;
	IFNEG(neg, str, i);
	ft_handle_integer(&nb, &str, &i, modulo);
	str = ft_handle_decimals(str, &i, nb, precision);
	i = (str[i] == '0') ? i++ : i;
	str = ft_check_fflags(&str, neg, pos);
	ft_putstr(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
