/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:40:55 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/02 14:40:56 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_error(int flag, char *message, t_ls *ft_ls)
{
	if (flag == 1)
		ft_printf("usage: ./ft_ls [-Rlratufgo] [file ...]\n");
	if (flag == 2)
		ft_printf("ft_ls: %s: No such file or directory\n", message);
	if (flag == 3)
		ft_printf("ft_ls: illegal option -- %c\n", *message);
	ft_ls->flags.t_f.print = 1;
}
