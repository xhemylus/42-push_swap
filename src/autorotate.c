/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autorotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:23:12 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 13:37:39 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	autorotate_a(t_ps *ps, int to_find)
{
	int	i;

	i = 0;
	while (ps->stack_a[i] != to_find)
		i++;
	while (ps->stack_a[0] != to_find)
	{
		if (i <= ps->size_a / 2)
			op_ra(ps, 1);
		else
			op_rra(ps, 1);
	}
}

void	autorotate_b(t_ps *ps, int to_find
)
{
	int	i;

	i = 0;
	while (ps->stack_b[i] != to_find)
		i++;
	while (ps->stack_b[0] != to_find)
	{
		if (i <= ps->size_b / 2)
			op_rb(ps, 1);
		else
			op_rrb(ps, 1);
	}
}

int	countrotate_a(t_ps *ps, int to_find)
{
	int	i;

	i = 0;
	while (ps->stack_a[i] != to_find)
		i++;
	if (i <= ps->size_a / 2)
		return (i);
	else
		return (ps->size_a - i + 1);
}

int	countrotate_b(t_ps *ps, int to_find)
{
	int	i;

	i = 0;
	while (ps->stack_b[i] != to_find)
		i++;
	if (i <= ps->size_b / 2)
		return (i);
	else
		return (ps->size_b - i + 1);
}
