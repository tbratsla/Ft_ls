/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_print_fi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:21:16 by tbratsla          #+#    #+#             */
/*   Updated: 2019/02/25 14:21:16 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_str_with_fgrid(char *pos, char **s)
{
	char *help;

	if (ft_strchr(pos, '#') && !ft_strchr(*s, '.'))
	{
		help = *s;
		*s = ft_strpjoin(*s, ".", ft_strlen(*s));
		free(help);
	}
	return (*s);
}
