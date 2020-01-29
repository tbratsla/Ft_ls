/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:18:30 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/06 16:18:30 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_xflags(char *pos, char **s)
{
	int		i;
	int		len;

	*s = ft_str_with_xgrid(pos, s);
	*s = ft_check_xdot(pos, s);
	*s = ft_str_with_xzero(pos, s);
	i = 0;
	*s = ft_check_xminus(pos, s, i);
	*s = ft_str_with_xdigits(pos, s);
	len = ft_strlen(*s);
	if (pos[ft_strlen(pos) - 1] == 'x')
		*s = ft_strdown(*s);
	else if (pos[ft_strlen(pos) - 1] == 'X')
		*s = ft_strup(*s);
	ft_putstr(*s);
	free(*s);
	return (len);
}

char	*ft_check_xdot(char *pos, char **s)
{
	char	*help;
	char	*chr;
	int		prec;

	if ((chr = ft_strchr(pos, '.')))
	{
		prec = ft_atoi(&chr[1]);
		prec = prec < 0 ? 0 : prec;
		if (ft_strchr(pos, '#'))
		{
			prec += 2;
			while ((size_t)prec > ft_strlen(*s))
				ADDP(*s, help);
		}
		else
			while ((size_t)prec > ft_strlen(*s))
			{
				help = *s;
				*s = ft_strjoin("0", help);
				free(help);
			}
	}
	return (*s);
}

int		ft_check_xzero(char *pos)
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

int		ft_check_xdigit(char *pos)
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

char	*ft_strdown(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		i++;
	}
	return (s);
}
