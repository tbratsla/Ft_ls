/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:24:19 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/10 15:24:20 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	free_double_str(char **str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_memdel((void **)str);
}
