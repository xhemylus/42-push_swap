/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:53:16 by abollen           #+#    #+#             */
/*   Updated: 2022/02/01 16:46:35 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_ps *ps, int echo)
{
	int	temp;

	if (ps->size_b < 1)
		return ;
	temp = ps->stack_b[0];
	op_rb(ps, 0);
	ps->size_b -= 1;
	ps->size_a += 1;
	op_rra(ps, 0);
	ps->stack_a[0] = temp;
	if (echo)
		write(1, "pa\n", 3);
}

void	op_pb(t_ps *ps, int echo)
{
	int	temp;

	if (ps->size_a < 1)
		return ;
	temp = ps->stack_a[0];
	op_ra(ps, 0);
	ps->size_a -= 1;
	ps->size_b += 1;
	op_rrb(ps, 0);
	ps->stack_b[0] = temp;
	if (echo)
		write(1, "pb\n", 3);
}
