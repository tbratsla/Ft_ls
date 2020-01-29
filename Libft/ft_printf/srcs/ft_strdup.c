/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:39:57 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/23 15:39:57 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *s1)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(new_line = malloc(ft_strlen((char*)s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		new_line[i] = s1[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
