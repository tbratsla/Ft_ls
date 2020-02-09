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

void	print_correct_file(t_files *file, int words, int count, t_ls *ft_ls)
{
	int		i;
	int		j;
	int		k;
	t_files *start;

	i = 0;
	while (i < words)
	{
		start = file;
		j = 0;
		while (j < words)
		{
			if ((file->direct_name[0] == '.' && ft_ls->flags.t_f.a == 1)\
				|| file->direct_name[0] != '.')
				ft_printf(ft_ls->str, file->direct_name);
			else
			{
				file = file->next;
				continue ;
			}
			k = 0;
			while (k < words && i + k < count)
			{
				k++;
				file = file->next;
			}
			j++;
		}
		file = start;
		file = file->next;
		ft_printf("\n");
		i++;
	}
}

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
		word = count / max_div(count, (ft_ls->win.ws_col / len));
	return (word);
}

char	*create_param_str(char *str, int max_len)
{
	int		len;
	char	*tmp;

	len = count_str_len(max_len);
	tmp = ft_itoa(len);
	str = ft_strjoin("%-", tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "s");
	free(tmp);
	return (str);
}

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

void	print_file(t_files *file, t_ls *ft_ls, int max_len, int count)
{
	t_files *begin;
	int		words_in_str;

	count = count - 1;
	words_in_str = count_word_in_str(ft_ls, max_len, count);
	ft_ls->str = create_param_str(ft_ls->str, max_len);
	begin = file;
	// ft_printf("count = %i words_in_str %i\n", count, words_in_str);
	if (count > words_in_str)
		print_correct_file(file, words_in_str, count, ft_ls);
	else		
		while (file)
		{
			if ((file->direct_name[0] == '.' && ft_ls->flags.t_f.a == 1) || file->direct_name[0] != '.')
					ft_printf(ft_ls->str, file->direct_name);
			file = file->next;
		}
	file = begin;
	free(ft_ls->str);
}
