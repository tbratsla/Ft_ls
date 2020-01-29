/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:06:38 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/06 16:06:39 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_x(va_list args, char *pos)
{
	int sum;

	if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] != 'h')
		sum = ft_print_hx(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] != 'l')
		sum = ft_print_lx(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] == 'l')
		sum = ft_print_llx(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] == 'h')
		sum = ft_print_hhx(args, pos);
	else
		sum = ft_print_ix(args, pos);
	return (sum);
}

int		ft_print_hx(va_list args, char *pos)
{
	unsigned short	d;
	int				len;
	char			*s;

	d = (unsigned short)va_arg(args, int);
	s = ft_itoa_base((unsigned long long)d, 16);
	len = ft_check_xflags(pos, &s);
	return (len);
}

int		ft_print_hhx(va_list args, char *pos)
{
	unsigned int	d;
	int				len;
	char			*s;

	d = (unsigned char)va_arg(args, int);
	s = ft_itoa_base((unsigned long long)d, 16);
	len = ft_check_xflags(pos, &s);
	return (len);
}

int		ft_print_lx(va_list args, char *pos)
{
	unsigned long	d;
	int				len;
	char			*s;

	d = va_arg(args, unsigned long);
	s = ft_itoa_base((unsigned long long)d, 16);
	len = ft_check_xflags(pos, &s);
	return (len);
}

int		ft_print_llx(va_list args, char *pos)
{
	unsigned long long	d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned long long);
	s = ft_itoa_base((unsigned long long)d, 16);
	len = ft_check_xflags(pos, &s);
	return (len);
}
