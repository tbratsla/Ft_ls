/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:33:27 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/07 13:33:28 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_count_amount(const char *format)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] &&
			format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1] &&
				format[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	int		count;
	char	**pos;
	int		amount;
	va_list	args;
	int		i;

	pos = NULL;
	CHECKFOR(format);
	amount = ft_count_amount(format);
	i = amount;
	if (amount != 0)
	{
		va_start(args, format);
		pos = ft_make_pos(format, &amount);
		IFNOT(pos, args);
	}
	count = ft_print(format, args, pos);
	if (amount != 0 && i)
	{
		va_end(args);
		if (amount)
			free_pos(pos, amount);
	}
	return (count);
}

int		ft_print(const char *format, va_list args, char **pos)
{
	int		i;
	int		a;
	int		count;

	TOZERO(i, a, count);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			ft_putchar(format[i]);
		}
		else if (pos && pos[a])
		{
			count += ft_create_str(args, pos[a]);
			ELIF(i, ft_strlen(pos[a]), a, count);
		}
		else
			return (count);
		i++;
		count++;
	}
	return (count);
}
