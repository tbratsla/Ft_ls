/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:47:24 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/25 13:47:25 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,\
					int c, size_t n)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;
	int				count;

	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	i = 0;
	count = 0;
	while ((i < n) && count == 0)
	{
		if (new_src[i] == (unsigned char)c)
			count = 1;
		new_dst[i] = new_src[i];
		i++;
	}
	if (count == 0)
		return (NULL);
	dst = new_dst;
	return (dst + i);
}
