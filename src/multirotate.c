/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multirotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:40:18 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 16:02:09 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direction_a(t_ps *ps, int to_find)
{
	int	i;

	i = 0;
	while (ps->stack_a[i] != to_find)
		i++;
	if (i <= ps->size_a / 2)
		return (1);
	else
		return (-1);
}

int	direction_b(t_ps *ps, int to_find)
{
	int	i;

	i = 0;
	while (ps->stack_b[i] != to_find)
		i++;
	if (i <= ps->size_b / 2)
		return (1);
	else
		return (-1);
}

void	multirotate(t_ps *ps, int to_finda, int to_findb)
{
	int	da;
	int	db;

	da = direction_a(ps, to_finda);
	db = direction_b(ps, to_findb);
	if (da == db)
	{
		while (ps->stack_a[0] != to_finda && ps->stack_b[0] != to_findb)
		{
			if (da == 1)
				op_rr(ps, 1);
			else
				op_rrr(ps, 1);
		}
	}
	autorotate_a(ps, to_finda);
	autorotate_b(ps, to_findb);
}
