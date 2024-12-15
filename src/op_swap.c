/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:22:47 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 14:39:41 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ps *ps, int echo)
{
	int	temp;

	temp = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = temp;
	if (echo == 1)
		write(1, "sa\n", 3);
}

void	op_sb(t_ps *ps, int echo)
{
	int	temp;

	temp = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = temp;
	if (echo == 1)
		write(1, "sb\n", 3);
}

void	op_ss(t_ps *ps, int echo)
{
	op_sa(ps, 0);
	op_sb(ps, 0);
	if (echo == 1)
		write(1, "ss\n", 3);
}
