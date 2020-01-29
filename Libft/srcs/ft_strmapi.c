/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:02:35 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/01 12:02:35 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new_mass;
	unsigned int		i;

	if (!s)
		return (NULL);
	new_mass = ft_strnew(ft_strlen((char*)s));
	if (!new_mass)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_mass[i] = f(i, s[i]);
		i++;
	}
	new_mass[i] = '\0';
	return (new_mass);
}
