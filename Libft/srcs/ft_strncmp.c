/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:03:14 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/27 15:03:15 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	s01 = (unsigned char*)s1;
	s02 = (unsigned char*)s2;
	i = -1;
	while (++i < n && s01[i] == s02[i] && s01[i])
		;
	if (i == n || (!s01[i] && !s02[i]))
		return (0);
	return (s01[i] - s02[i]);
}
