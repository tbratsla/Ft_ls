/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:38:31 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/28 12:38:31 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_llgenlenn(long long n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_long_itoa(long long n)
{
	char					*s1;
	unsigned long long		newn;
	size_t					len;

	len = ft_llgenlenn(n);
	newn = n;
	if (n < 0)
	{
		newn = -n;
		len++;
	}
	if (!(s1 = ft_strnew(len)))
		return (NULL);
	s1[--len] = newn % 10 + '0';
	while (newn /= 10)
		s1[--len] = newn % 10 + '0';
	if (n < 0)
		*(s1 + 0) = '-';
	return (s1);
}
