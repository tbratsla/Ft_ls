/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:20:29 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/13 15:20:30 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_f(va_list args, char *pos)
{
	int		sum;
	char	*chr;
	int		prec;

	if ((chr = ft_strchr(pos, '.')))
		prec = ft_atoi(&chr[1]) + 1;
	else
		prec = 7;
	if (pos[ft_strlen(pos) - 2] == 'L')
		sum = ft_print_llf(args, prec, &pos);
	else if (pos[ft_strlen(pos) - 2] == 'l')
		sum = ft_print_lf(args, prec, &pos);
	else
		sum = ft_print_if(args, prec, &pos);
	return (sum);
}

int		ft_print_llf(va_list args, int prec, char **pos)
{
	int			len;
	long double	d;

	d = va_arg(args, long double);
	len = ft_put_float_to_string(d, prec, pos);
	return (len);
}

int		ft_print_lf(va_list args, int prec, char **pos)
{
	int			len;
	double		d;

	d = va_arg(args, double);
	len = ft_put_float_to_string((long double)d, prec, pos);
	return (len);
}

int		ft_print_if(va_list args, int prec, char **pos)
{
	int			len;
	double		d;

	d = va_arg(args, double);
	len = ft_put_float_to_string((long double)d, prec, pos);
	return (len);
}
