/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:09 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/25 14:38:10 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_d(va_list args, char *pos)
{
	int sum;

	if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] != 'h')
		sum = ft_print_hd(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] != 'l')
		sum = ft_print_ld(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] == 'l')
		sum = ft_print_lld(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] == 'h')
		sum = ft_print_hhd(args, pos);
	else
		sum = ft_print_id(args, pos);
	return (sum);
}

int		ft_print_hd(va_list args, char *pos)
{
	short	d;
	int		len;
	char	*s;

	d = (short)va_arg(args, int);
	s = ft_itoa((int)d);
	len = ft_check_flags(pos, &s, (long long)d);
	return (len);
}

int		ft_print_hhd(va_list args, char *pos)
{
	int		d;
	int		len;
	char	*s;

	d = (char)va_arg(args, int);
	s = ft_long_itoa((long long)d);
	len = ft_check_flags(pos, &s, (long long)d);
	return (len);
}

int		ft_print_ld(va_list args, char *pos)
{
	long	d;
	int		len;
	char	*s;

	d = va_arg(args, long);
	s = ft_long_itoa(d);
	len = ft_check_flags(pos, &s, (long long)d);
	return (len);
}

int		ft_print_lld(va_list args, char *pos)
{
	long long	d;
	int			len;
	char		*s;

	d = va_arg(args, long long);
	s = ft_long_itoa(d);
	len = ft_check_flags(pos, &s, (long long)d);
	return (len);
}
