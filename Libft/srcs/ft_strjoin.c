/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:50:11 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/01 12:50:11 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
	{
		newstr[i] = s2[j];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
