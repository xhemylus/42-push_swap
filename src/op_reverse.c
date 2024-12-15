/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:35:46 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 14:40:57 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ps *ps, int echo)
{
	int	temp;
	int	i;

	temp = ps->stack_a[ps->size_a - 1];
	i = ps->size_a;
	while (--i > 0)
		ps->stack_a[i] = ps->stack_a[i - 1];
	ps->stack_a[0] = temp;
	if (echo)
		write(1, "rra\n", 4);
}

void	op_rrb(t_ps *ps, int echo)
{
	int	temp;
	int	i;

	temp = ps->stack_b[ps->size_b - 1];
	i = ps->size_b;
	while (--i > 0)
		ps->stack_b[i] = ps->stack_b[i - 1];
	ps->stack_b[0] = temp;
	if (echo)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_ps *ps, int echo)
{
	op_rra(ps, 0);
	op_rrb(ps, 0);
	if (echo)
		write(1, "rrr\n", 4);
}
