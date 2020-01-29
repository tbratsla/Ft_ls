/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:42:07 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/31 12:42:07 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_u(va_list args, char *pos)
{
	int sum;

	if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] != 'h')
		sum = ft_print_hu(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] != 'l')
		sum = ft_print_lu(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] == 'l')
		sum = ft_print_llu(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] == 'h')
		sum = ft_print_hhu(args, pos);
	else
		sum = ft_print_iu(args, pos);
	return (sum);
}

int		ft_print_hu(va_list args, char *pos)
{
	unsigned short	d;
	int				len;
	char			*s;

	d = (unsigned short)va_arg(args, int);
	s = ft_unsigned_long_itoa((int)d);
	len = ft_check_uflags(pos, &s);
	return (len);
}

int		ft_print_hhu(va_list args, char *pos)
{
	unsigned int	d;
	int				len;
	char			*s;

	d = (unsigned char)va_arg(args, int);
	s = ft_unsigned_long_itoa((unsigned long long)d);
	len = ft_check_uflags(pos, &s);
	return (len);
}

int		ft_print_lu(va_list args, char *pos)
{
	unsigned long	d;
	int				len;
	char			*s;

	d = va_arg(args, unsigned long);
	s = ft_unsigned_long_itoa(d);
	len = ft_check_uflags(pos, &s);
	return (len);
}

int		ft_print_llu(va_list args, char *pos)
{
	unsigned long long	d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned long long);
	s = ft_unsigned_long_itoa(d);
	len = ft_check_uflags(pos, &s);
	return (len);
}
