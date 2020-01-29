/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:31:14 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/26 12:31:15 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	s01 = (unsigned char*)s1;
	s02 = (unsigned char*)s2;
	i = -1;
	while (++i < n && s01[i] == s02[i])
		;
	if (i == n)
		return (0);
	return (s01[i] - s02[i]);
}
