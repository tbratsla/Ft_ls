/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:07:58 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/01 13:07:59 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkj(char const *s)
{
	int		j;

	j = ft_strlen((char*)s) - 1;
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		j--;
	return (j);
}

static	int	ft_checki(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*newstr;

	if (!s)
		return (NULL);
	i = ft_checki(s);
	k = 0;
	j = ft_checkj(s);
	if (i > j + 1)
		i = j;
	newstr = ft_strnew(j - i + 1);
	if (!newstr)
		return (NULL);
	if (!s[i] || !s[j] || i >= j)
		return (newstr);
	while (i <= j)
	{
		newstr[k] = s[i];
		i++;
		k++;
	}
	newstr[k] = '\0';
	return (newstr);
}
