/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:17:12 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/20 15:17:13 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_s(va_list args, char *pos)
{
	int		i;
	char	*s;
	int		len;

	if (!(s = ft_strdup(va_arg(args, char *))))
		s = ft_strdup("(null)");
	len = ft_atoi(pos);
	i = len;
	s = ft_check_sdot(pos, s);
	s = ft_str_with_perzero(pos, &s);
	if (len < 0)
	{
		MIO(ft_putstr(s), len, i);
		ft_while_to_s(len, s);
	}
	else
	{
		ft_while_to_s(len, s);
		ft_putstr(s);
	}
	len = ft_strlen(s);
	free(s);
	if (i > len)
		return (i);
	return (len);
}

char	*ft_check_sdot(char *pos, char *s)
{
	char	*help;
	char	*chr;
	int		prec;
	int		i;

	i = 0;
	if ((chr = ft_strchr(pos, '.')))
	{
		prec = ft_atoi(&chr[1]);
		if (prec < 0)
			prec = 0;
		help = ft_strnew(prec);
		while (i < prec && s[i])
		{
			help[i] = s[i];
			i++;
		}
		free(s);
		return (help);
	}
	return (s);
}

void	ft_while_to_s(int len, char *s)
{
	while ((size_t)len > ft_strlen(s))
	{
		ft_putchar(' ');
		len--;
	}
}
