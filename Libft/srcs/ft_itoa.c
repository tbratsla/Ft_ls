/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:45:24 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/05 11:45:24 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*s1;
	unsigned int	newn;
	size_t			len;

	len = ft_genlenn(n);
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
