/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:00 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/26 14:09:00 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_flags(char *pos, char **s, long long d)
{
	int		i;

	*s = ft_check_dot(pos, s, d);
	*s = ft_check_plus(pos, s, d);
	*s = ft_str_with_zero(pos, s, d);
	i = 0;
	*s = ft_check_minus(pos, s, i);
	*s = ft_str_with_digits(pos, s);
	i = ft_strlen(*s);
	ft_putstr(*s);
	free(*s);
	return (i);
}

char	*ft_check_dot(char *pos, char **s, long long d)
{
	char	*help;
	char	*chr;
	int		prec;

	if ((chr = ft_strchr(pos, '.')))
	{
		prec = ft_atoi(&chr[1]);
		prec = prec < 0 ? 0 : prec;
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			if (d < 0)
				*s = ft_strpjoin(help, "0", 1);
			else
				*s = ft_strjoin("0", help);
			free(help);
		}
		if (d < 0)
		{
			help = *s;
			*s = ft_strpjoin(help, "0", 1);
			free(help);
		}
	}
	return (*s);
}

int		ft_check_zero(char *pos)
{
	int i;

	i = 0;
	while (pos[i])
	{
		if ((pos[i] >= '1' && pos[i] <= '9') || pos[i] == '.')
		{
			return (-1);
		}
		if (pos[i] == '0')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_check_digit(char *pos)
{
	int i;

	i = 0;
	while (pos[i])
	{
		if (pos[i] == '.')
			return (-1);
		if ((pos[i] >= '1' && pos[i] <= '9'))
			return (i);
		i++;
	}
	return (-1);
}
