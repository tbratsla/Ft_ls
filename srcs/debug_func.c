/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:19:43 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/06 15:19:43 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_direct(t_dir *direct)
{
	t_dir *begin;

	begin = direct;
	while (begin)
	{
		ft_printf("%s\n", begin->filename);
		begin = begin->next;
	}
}
