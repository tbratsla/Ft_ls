/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:18:49 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/01 11:18:50 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_mass;
	int		i;

	if (!s)
		return (NULL);
	new_mass = ft_strnew(ft_strlen((char*)s));
	if (!new_mass)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_mass[i] = f(s[i]);
		i++;
	}
	new_mass[i] = '\0';
	return (new_mass);
}
