/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:57:35 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/27 13:57:36 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (!ft_strlen((char*)needle))
		return ((char*)haystack);
	if (!(ft_strlen((char*)haystack) < ft_strlen((char*)needle)))
		while (haystack[++i] && i < len)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				while (haystack[i + j] == needle[j] && (i + j) < len)
				{
					j++;
					if (!(needle[j]))
						return ((char*)&haystack[i]);
				}
			}
		}
	return (NULL);
}
