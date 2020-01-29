/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:58:12 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/31 12:58:12 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_str_with_uzero(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0 && \
		!ft_strchr(pos, '.') && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i + 1]);
		if (!(ft_strchr(pos, '+')))
			while ((size_t)prec > ft_strlen(*s))
			{
				help = *s;
				*s = ft_strjoin("0", help);
				free(help);
			}
	}
	return (*s);
}

char	*ft_str_with_udigits(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_digit(pos)) >= 0 && !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i]);
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin(" ", help);
			free(help);
		}
	}
	return (*s);
}

char	*ft_check_uminus(char *pos, char **s, int i)
{
	char	*help;
	int		prec;

	prec = (int)ft_strlen(*s);
	if ((ft_strchr(pos, '-')))
	{
		while (pos[i])
		{
			if (pos[i] >= '1' && pos[i] <= '9')
			{
				prec = ft_atoi(&pos[i]);
				break ;
			}
			if (pos[i] == '.')
				break ;
			i++;
		}
		while ((size_t)prec > ft_strlen(*s))
		{
			help = *s;
			*s = ft_strjoin(help, " ");
			free(help);
		}
	}
	return (*s);
}

char	*ft_check_uplus(char *pos, char **s)
{
	char	*help;

	if (ft_strchr(pos, '+'))
	{
		help = *s;
		*s = ft_strjoin("+", help);
		free(help);
	}
	if ((ft_strchr(pos, ' ')) && !(ft_strchr(pos, '+')))
	{
		help = *s;
		*s = ft_strjoin(" ", help);
		free(help);
	}
	return (*s);
}
