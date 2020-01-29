/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:28:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/16 12:28:03 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_create_str(va_list args, char *pos)
{
	int len;

	if (pos[ft_strlen(pos) - 1] == 'c')
		len = ft_print_c(args, pos);
	if (pos[ft_strlen(pos) - 1] == 's')
		len = ft_print_s(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'p')
		len = ft_print_p(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'd')
		len = ft_print_d(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'i')
		len = ft_print_d(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'o')
		len = ft_print_o(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'u')
		len = ft_print_u(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'x')
		len = ft_print_x(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'X')
		len = ft_print_x(args, pos);
	if (pos[ft_strlen(pos) - 1] == 'f')
		len = ft_print_f(args, pos);
	if (pos[ft_strlen(pos) - 1] == '%')
		len = ft_print_per(pos);
	return (len);
}
