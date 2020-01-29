/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:54:22 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/01 17:54:23 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*handle_else(int *i, char *str, int *number)
{
	int		k;
	char	*s;

	k = --(*i);
	while (k >= 0 && (str[k] == '9' || str[k] == '.'))
	{
		if (str[k] == '9')
			str[k] = '0';
		k--;
	}
	if (k < 0 && str[0] == '0')
	{
		ADDONE(str, s, i);
	}
	else
	{
		*number = str[k] - '0';
		(*number)++;
		str[k] = *number + '0';
	}
	return (str);
}

char	*handle_else_two(int *i, char *str, int *number)
{
	int		k;
	char	*s;

	k = --(*i);
	while (k >= 0 && (str[k] == '9' || str[k] == '.'))
	{
		if (str[k] == '9')
			str[k] = '0';
		k--;
	}
	if (k < 0 && str[0] == '0')
	{
		ADDONE(str, s, i);
	}
	else if (str[0] == '-')
	{
		ADDPONE(str, s, i);
	}
	else
	{
		*number = str[k] - '0';
		(*number)++;
		str[k] = *number + '0';
	}
	return (str);
}

char	*handle_if(int j[4], char *str, long int *i, long double nb)
{
	int k;

	k = 0;
	if (j[3] - 1 > 0)
		str[(*i)++] = '.';
	else if ((long int)nb % 10 < 5)
	{
		str[(*i)++] = (char)((long int)nb + 48);
		k++;
	}
	else if ((long int)nb % 10 >= 5 && (ft_atoi(&str[ft_strlen(str) - 1]) != 9))
	{
		if (!((long int)nb % 10 == 5) || \
			!(ft_atoi(&str[ft_strlen(str) - 1]) % 2 == 0) || \
			(long int)(nb * 10) % 10)
			ADDSTR(j[2], str, i);
	}
	else
		ABCD(j[1], i, str, j[2]);
	if (k)
		str[(*i) - 1] = '\0';
	return (str);
}
