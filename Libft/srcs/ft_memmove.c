/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:18:15 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/25 15:18:16 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*newsrc;
	char	*newdst;
	size_t	i;

	i = -1;
	newsrc = (char*)src;
	newdst = (char*)dst;
	if (newsrc < newdst)
		while ((int)(--len) >= 0)
			*(newdst + len) = *(newsrc + len);
	else
		while (++i < len)
			*(newdst + i) = *(newsrc + i);
	return (dst);
}
