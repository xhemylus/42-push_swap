/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:37:07 by abollen           #+#    #+#             */
/*   Updated: 2022/02/03 14:40:42 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ps *ps, int echo)
{
	int	temp;
	int	i;

	if (ps->size_a == 0)
		return ;
	temp = ps->stack_a[0];
	i = 0;
	while (++i < ps->size_a)
		ps->stack_a[i - 1] = ps->stack_a[i];
	ps->stack_a[i - 1] = temp;
	if (echo)
		write(1, "ra\n", 3);
}

void	op_rb(t_ps *ps, int echo)
{
	int	temp;
	int	i;

	if (ps->size_b == 0)
		return ;
	temp = ps->stack_b[0];
	i = 0;
	while (++i < ps->size_b)
		ps->stack_b[i - 1] = ps->stack_b[i];
	ps->stack_b[i - 1] = temp;
	if (echo)
		write(1, "rb\n", 3);
}

void	op_rr(t_ps *ps, int echo)
{
	op_ra(ps, 0);
	op_rb(ps, 0);
	if (echo)
		write(1, "rr\n", 3);
}
