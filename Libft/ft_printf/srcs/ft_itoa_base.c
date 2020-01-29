/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:17:40 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/05 13:17:40 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str) - 1;
	while (length > i)
	{
		buff = str[i];
		str[i] = str[length];
		str[length] = buff;
		length--;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	unsigned long long	n;
	int					i;
	char				*str;
	int					len;
	char				*help;

	n = value;
	len = 1;
	i = 0;
	while ((n /= base) > 1)
		len++;
	str = ft_strnew(len + 1);
	while (i <= len)
	{
		if (value % base < 10)
			str[i] = value % base + '0';
		else
			str[i] = value % base + 'A' - 10;
		value /= base;
		i++;
	}
	help = str;
	str = ft_strrev(help);
	DUP(str, help);
	return (str);
}
