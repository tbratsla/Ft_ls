/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:46:27 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/01 17:46:27 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_id(va_list args, char *pos)
{
	int		d;
	int		len;
	char	*s;

	d = va_arg(args, int);
	s = ft_itoa((int)d);
	len = ft_check_flags(pos, &s, (long long)d);
	return (len);
}
