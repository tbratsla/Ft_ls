/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:57:43 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/11 15:57:44 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		max_div(int a, int b)
{
	if (a % b == 0)
		return (a / b);
	return (a / b + 1);
}

int		count_str_len(int max_len)
{
	int i;

	i = 8;
	while (i <= max_len)
		i += 8;
	return (i);
}

int		count_word_in_str(t_ls *ft_ls, int max_len, int count)
{
	int		len;
	int		word;

	len = count_str_len(max_len);
	if (len * count < ft_ls->win.ws_col)
		word = count;
	else
		word = max_div(count, max_div(count, (ft_ls->win.ws_col / len)));
	return (word);
}

char	**get_double_str(t_files *file, int count)
{
	char	**str;
	int		i;
	t_files *start;

	str = ft_memalloc(sizeof(char *) * count);
	start = file;
	i = 0;
	while (start)
	{
		if (start->direct_name[0] != '.')
		{
			str[i] = ft_strdup(start->direct_name);
			i++;
		}
		start = start->next;
	}
	return (str);
}
