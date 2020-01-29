/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:31:09 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/28 13:31:09 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	if (!(c = malloc(size)))
		return (NULL);
	else
	{
		while (size > i)
		{
			c[i] = '\0';
			i++;
		}
	}
	return ((void*)c);
}
