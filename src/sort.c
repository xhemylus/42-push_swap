/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:23:20 by abollen           #+#    #+#             */
/*   Updated: 2022/02/04 14:50:06 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sorthandler(t_ps *ps)
{
	if (ps->total == 3)
		sort_three(ps);
	else if (ps->total <= 5)
		smallsort(ps);
	else
		bucketsort_b(ps);
}

void	sort_three(t_ps *ps)
{
	if (ps->stack_a[0] == 1 && ps->stack_a[1] == 0)
		op_sa(ps, 1);
	else if (ps->stack_a[0] == 2 && ps->stack_a[1] == 1)
	{
		op_sa(ps, 1);
		op_rra(ps, 1);
	}
	else if (ps->stack_a[0] == 2 && ps->stack_a[1] == 0)
		op_ra(ps, 1);
	else if (ps->stack_a[0] == 0 && ps->stack_a[1] == 2)
	{
		op_sa(ps, 1);
		op_ra(ps, 1);
	}
	else if (ps->stack_a[0] == 1 && ps->stack_a[1] == 2)
		op_rra(ps, 1);
}

void	smallsort(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (ps->stack_a[j] < ps->total - 2)
			j++;
		if (j > 0)
			autorotate_a(ps, ps->stack_a[j]);
		op_pb(ps, 1);
		i++;
	}
	sort_three(ps);
	if (ps->stack_b[0] < ps->stack_b[1])
		op_rb(ps, 1);
	op_pa(ps, 1);
	op_pa(ps, 1);
	op_ra(ps, 1);
	op_ra(ps, 1);
}

void	bucketsort_b(t_ps *ps)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (ps->size_a > 0)
	{
		i++;
		if (i % ps->bucket_size == 0)
			j++;
		ps->bucket_limit[0] = j * ps->bucket_size;
		ps->bucket_limit[1] = (j + 1) * ps->bucket_size - 1;
		while (ps->stack_a[0] < ps->bucket_limit[0]
			|| ps->stack_a[0] > ps->bucket_limit[1])
			op_ra(ps, 1);
		op_pb(ps, 1);
	}
	insert(ps);
	ps->bucket_size /= 2;
	i = ps->total;
	autorotate_a(ps, 0);
}
