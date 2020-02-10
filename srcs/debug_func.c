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

int		max_div(int a, int b)
{
	if (a % b == 0)
		return (a / b);
	return (a / b + 1);
}

char	**get_double_str(t_files *file, int count)
{
	char **str;
	int i;
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

void	print_output_str(t_files *file, int words, int count, t_ls *ft_ls)
{
	int i;
	int	j;
	char **str;

	str = get_double_str(file, count);
	i = 0;
	while (i < max_div(count, words))
	{
		j = i;
		while(j < count)
		{
			if (str[j])
				ft_printf(ft_ls->str, str[j]);
			j += max_div(count, words);
		}
		if (i + 1 < max_div(count, words))
			ft_printf("\n");
		i++;
	}

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
			ft_printf(ft_ls->str, start->direct_name);
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
