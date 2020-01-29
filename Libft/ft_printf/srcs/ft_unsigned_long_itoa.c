/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_long_itoa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:51:15 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/31 12:51:16 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_ugenlenn(unsigned long long n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_unsigned_long_itoa(unsigned long long n)
{
	char					*s1;
	unsigned long long		newn;
	size_t					len;

	len = ft_ugenlenn(n);
	newn = n;
	if (!(s1 = ft_strnew(len)))
		return (NULL);
	s1[--len] = newn % 10 + '0';
	while (newn /= 10)
		s1[--len] = newn % 10 + '0';
	return (s1);
}
