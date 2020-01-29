/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:06:01 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/01 16:06:01 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strup(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
		i++;
	}
	return (s);
}

int		ft_print_ix(va_list args, char *pos)
{
	unsigned int		d;
	int					len;
	char				*s;

	d = va_arg(args, unsigned int);
	s = ft_itoa_base((unsigned long long)d, 16);
	len = ft_check_xflags(pos, &s);
	return (len);
}
