/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:36:21 by abollen           #+#    #+#             */
/*   Updated: 2022/02/08 15:08:21 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksort(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->total - 1)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	checkdoublon(t_ps *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->total - 1)
	{
		j = i;
		while (++j < ps->total)
		{
			if (ps->stack_a[i] == ps->stack_a[j])
				ft_error("Error\n");
		}
	}
}

void	stack_init(char *ar, t_ps *ps)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ps->stack_a = malloc(sizeof(int) * ps->total - 1);
	if (!ps->stack_a)
		ft_error("Error\n");
	while (ar[i] || i < (int)ft_strlen(ar))
	{
		if (ar[i] == ' ')
			i++;
		else
		{
			if (ft_atoi(&ar[i]) > 2147483647 || ft_atoi(&ar[i]) < -2147483648)
			{
				free(ps->stack_a);
				ft_error("Error\n");
			}
			ps->stack_a[j++] = (int)ft_atoi(&ar[i]);
			while (ft_isdigit(ar[i]) || ar[i] == '-')
				i++;
		}
	}
}

void	paramcheck(char *array, t_ps *ps)
{
	checkint(array);
	stack_init(array, ps);
	checkdoublon(ps);
	ps->stack_b = malloc(sizeof(int) * ps->total);
	if (!ps->stack_b)
	{
		free(ps->stack_a);
		ft_error("Error\n");
	}
	ps->size_a = ft_wordcount(array, ' ');
	ps->size_b = 0;
	ps->bucket_size = bucketinit(ps);
}
