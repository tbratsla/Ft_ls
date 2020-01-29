/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:04:40 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/01 17:04:40 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_io(va_list args, char *pos)
{
	unsigned int		d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned int);
	s = ft_itoa_base((unsigned long long)d, 8);
	len = ft_check_oflags(pos, &s);
	return (len);
}
