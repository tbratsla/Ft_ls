/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_xi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:18:39 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/06 16:18:40 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_str_with_xzero(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_zero(pos)) >= 0 && !ft_strchr(pos, '.')\
		&& !(ft_strchr(pos, '-')))
	{
		prec = ft_atoi(&pos[i + 1]);
		if (ft_strchr(pos, '#'))
		{
			if (!(ft_strchr(pos, '+')))
				while ((size_t)prec > ft_strlen(*s))
					ADDP(*s, help);
		}
		else if (!(ft_strchr(pos, '+')))
			while ((size_t)prec > ft_strlen(*s))
				ADD(*s, help);
	}
	return (*s);
}

char	*ft_str_with_xdigits(char *pos, char **s)
{
	char	*help;
	int		prec;
	int		i;

	if ((i = ft_check_xdigit(pos)) >= 0 && !(ft_strchr(pos, '-')))
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

char	*ft_check_xminus(char *pos, char **s, int i)
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

char	*ft_check_xplus(char *pos, char **s)
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

char	*ft_str_with_xgrid(char *pos, char **s)
{
	char	*help;

	if (pos[ft_strlen(pos) - 1] == 'x')
	{
		if (ft_strchr(pos, '#'))
		{
			help = *s;
			*s = ft_strjoin("0x", help);
			free(help);
		}
	}
	else if (pos[ft_strlen(pos) - 1] == 'X')
		if (ft_strchr(pos, '#'))
		{
			help = *s;
			*s = ft_strjoin("0x", help);
			free(help);
		}
	return (*s);
}
