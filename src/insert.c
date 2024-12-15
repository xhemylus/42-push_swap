/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:48:53 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 13:39:56 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findspot(t_ps *ps, int to_place)
{
	int	min;
	int	f_upper;
	int	i;

	if (ps->size_a == 0)
		return (0);
	min = ps->stack_a[0];
	f_upper = -1;
	i = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] < min)
			min = ps->stack_a[i];
		if (ps->stack_a[i] > to_place)
		{
			if (ps->stack_a[i] - to_place < f_upper - to_place || f_upper == -1)
				f_upper = ps->stack_a[i];
		}
		i++;
	}
	if (f_upper > -1)
		return (f_upper);
	else
		return (min);
}

int	getminmove_b(t_ps *ps)
{
	int	i;
	int	min;
	int	temp;
	int	res;

	i = 0;
	min = 2147483647;
	res = -1;
	while (i < ps->size_b)
	{
		temp = 0;
		temp += countrotate_b(ps, ps->stack_b[i]) - ps->stack_b[i] / 2;
		temp += countrotate_a(ps, findspot(ps, ps->stack_b[i]));
		if (temp < min)
		{
			min = temp;
			res = ps->stack_b[i];
		}
		i++;
	}
	return (res);
}

void	insert(t_ps *ps)
{
	while (ps->size_b > 0)
	{
		if (ps->size_a > 0)
		{
			multirotate(ps, findspot(ps, getminmove_b(ps)), getminmove_b(ps));
		}
		op_pa(ps, 1);
	}
}
