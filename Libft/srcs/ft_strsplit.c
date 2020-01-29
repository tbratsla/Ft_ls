/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:54:25 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/02 16:54:25 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**newstr;
	int		i;
	int		j;
	int		a;

	if (!s || !(newstr = (char**)malloc(sizeof(*newstr)\
										* (ft_count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_count_words(s, c))
	{
		a = 0;
		if (!(newstr[i] = ft_strnew(ft_getlen(&s[j], c) + 1)))
			newstr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			newstr[i][a++] = s[j++];
		newstr[i][a] = '\0';
	}
	newstr[i] = 0;
	return (newstr);
}
