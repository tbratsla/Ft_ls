/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:54:42 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/05 13:54:43 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_o(va_list args, char *pos)
{
	int sum;

	if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] != 'h')
		sum = ft_print_ho(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] != 'l')
		sum = ft_print_lo(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'l' && pos[ft_strlen(pos) - 3] == 'l')
		sum = ft_print_llo(args, pos);
	else if (pos[ft_strlen(pos) - 2] == 'h' && pos[ft_strlen(pos) - 3] == 'h')
		sum = ft_print_hho(args, pos);
	else
		sum = ft_print_io(args, pos);
	return (sum);
}

int		ft_print_ho(va_list args, char *pos)
{
	unsigned short	d;
	int				len;
	char			*s;

	d = (unsigned short)va_arg(args, int);
	s = ft_itoa_base((unsigned long long)d, 8);
	len = ft_check_oflags(pos, &s);
	return (len);
}

int		ft_print_hho(va_list args, char *pos)
{
	unsigned int	d;
	int				len;
	char			*s;

	d = (unsigned char)va_arg(args, int);
	s = ft_itoa_base((unsigned long long)d, 8);
	len = ft_check_oflags(pos, &s);
	return (len);
}

int		ft_print_lo(va_list args, char *pos)
{
	unsigned long	d;
	int				len;
	char			*s;

	d = va_arg(args, unsigned long);
	s = ft_itoa_base((unsigned long long)d, 8);
	len = ft_check_oflags(pos, &s);
	return (len);
}

int		ft_print_llo(va_list args, char *pos)
{
	unsigned long long	d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned long long);
	s = ft_itoa_base((unsigned long long)d, 8);
	len = ft_check_oflags(pos, &s);
	return (len);
}
