/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:15:31 by tbratsla          #+#    #+#             */
/*   Updated: 2018/10/28 16:15:32 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char*)malloc(sizeof(char) * size + 1);
	if (!c)
		return (NULL);
	ft_bzero(c, size + 1);
	return (c);
}
