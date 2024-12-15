/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:56:14 by abollen           #+#    #+#             */
/*   Updated: 2022/02/08 16:43:44 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static long	convert(const char *str, int i, long factor)
{
	long	num;

	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		if (num * factor > INT_MAX || num * factor < INT_MIN)
			ft_error("Error\n");
		i++;
	}
	return (num);
}

long	ft_atoi(const char *str)
{
	long	factor;
	int		i;
	long	r;

	factor = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		factor = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		factor = 1;
		i++;
	}	
	r = convert(str, i, factor);
	return (r * factor);
}
