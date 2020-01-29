/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:32:30 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/27 13:32:30 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strpjoin(char const *s1, char const *s2, int p)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	i = 0;
	j = 0;
	while (i < p)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	while (s1[i - j])
	{
		newstr[i] = s1[i - j];
		i++;
	}
	return (newstr);
}
