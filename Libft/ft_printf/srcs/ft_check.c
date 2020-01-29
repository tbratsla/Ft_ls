/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:07:32 by tbratsla          #+#    #+#             */
/*   Updated: 2018/11/01 12:07:32 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check(unsigned long long res, int sign)
{
	if (res > 9223372036854775808U && sign == -1)
		return (0);
	if (res > 9223372036854775807U && sign == 1)
		return (-1);
	else
		return ((int)res * sign);
}
