/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:54:49 by tbratsla          #+#    #+#             */
/*   Updated: 2020/02/11 15:54:50 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_output_str(t_files *file, int words, int count, t_ls *ft_ls)
{
	int		i;
	int		j;
	char	**str;

	str = get_double_str(file, count);
	i = 0;
	while (i < max_div(count, words))
	{
		j = i;
		while (j < count)
		{
			if (str[j])
				ft_printf(ft_ls->str, str[j]);
			j += max_div(count, words);
		}
		ft_printf("\n");
		i++;
	}
	free_double_str(str, count);
}

void	print_output_list(t_files *file, int words, int count, t_ls *ft_ls)
{
	t_files	*start;
	int		i;
	int		j;

	i = 0;
	start = file;
	while (i < words)
	{
		if (start)
			ft_printf(ft_ls->str, start->data->direct_name);
		j = 0;
		while (j < max_div(count, words) && start)
		{
			j++;
			start = start->next;
		}
		i++;
	}
}

void	print_correct_file(t_files *file, int words, int count, t_ls *ft_ls)
{
	int		i;

	i = 0;
	if (ft_ls->flags.t_f.a == 0)
		print_output_str(file, words, count, ft_ls);
	else
		while (i < max_div(count, words))
		{
			print_output_list(file, words, count, ft_ls);
			ft_printf("\n");
			i++;
			file = file->next;
		}
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

void	print_file(t_files *file, t_ls *ft_ls, int max_len, int count)
{
	t_files *begin;
	int		words_in_str;

	ft_ls->flags.t_f.print = 1;
	words_in_str = count_word_in_str(ft_ls, max_len, count);
	ft_ls->str = create_param_str(ft_ls->str, max_len);
	begin = file;
	if (count > words_in_str)
		print_correct_file(file, words_in_str, count, ft_ls);
	else
	{
		while (file)
		{
			if ((file->data->direct_name[0] == '.'\
				&& ft_ls->flags.t_f.a == 1) || file->data->direct_name[0] != '.')
			{
				ft_printf(ft_ls->str, file->data->direct_name);
			}
			file = file->next;
		}
		ft_printf("\n");
	}
	file = begin;
	free(ft_ls->str);
}
