/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:32:52 by abollen           #+#    #+#             */
/*   Updated: 2022/03/02 17:07:21 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *to_sort, int len)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < len)
	{
		j = 0;
		while (++j < len - i)
		{
			if (to_sort[j - 1] > to_sort[j])
			{
				temp = to_sort[j - 1];
				to_sort[j - 1] = to_sort[j];
				to_sort[j] = temp;
			}
		}
	}
}

static void	copy_array(int *from, int *to, int len, t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < len)
		to[i] = from[i];
	bubble_sort (ps->stack_b, ps->total);
}

void	to_index(t_ps *ps)
{
	int	i;
	int	j;

	ps->temp = malloc(sizeof(int) * ps->total);
	if (!ps->temp)
	{
		free(ps->stack_a);
		ft_error("Error\n");
	}	
	copy_array(ps->stack_a, ps->stack_b, ps->total, ps);
	i = -1;
	while (++i < ps->total)
	{
		ps->temp[i] = 1;
		j = -1;
		while (++j < ps->total)
		{
			if (ps->stack_a[i] == ps->stack_b[j] && ps->temp[i])
			{
				ps->stack_a[i] = j;
				ps->temp[i] = 0;
			}
		}
	}
	free (ps->temp);
}

int	bucketinit(t_ps *ps)
{
	if (ps->total == 100)
		return (40);
	else
		return (60);
}
