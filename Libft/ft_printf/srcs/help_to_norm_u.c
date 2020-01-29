/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:47:36 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/01 16:47:37 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_iu(va_list args, char *pos)
{
	unsigned int		d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned int);
	s = ft_unsigned_long_itoa((unsigned int)d);
	len = ft_check_uflags(pos, &s);
	return (len);
}
