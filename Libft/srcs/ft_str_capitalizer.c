/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:11:50 by exam              #+#    #+#             */
/*   Updated: 2018/10/30 11:33:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_capitalizer(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] >= 'a' && av[i][0] <= 'z')
				av[i][j] = av[i][j] - 'a' + 'A';
			else if (av[i][j] >= 'a' && av[i][j] <= 'z' && \
					!(av[i][j - 1] >= 33 && av[i][0] <= 126))
				av[i][j] = av[i][j] - 'a' + 'A';
			else if (av[i][j] >= 'A' && av[i][j] <= 'Z' && \
					(av[i][j - 1] >= 33 && av[i][0] <= 126))
				av[i][j] = av[i][j] - 'A' + 'a';
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
