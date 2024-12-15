/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:08:15 by abollen           #+#    #+#             */
/*   Updated: 2022/02/16 17:26:28 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	badinput(t_ps *ps, char *line)
{
	write(1, "Error\n", 6);
	free(ps->stack_a);
	free(ps->stack_b);
	free(line);
	exit(1);
}

void	operator(t_ps *ps, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		op_sa(ps, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		op_sb(ps, 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		op_ss(ps, 0);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		op_pa(ps, 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		op_pb(ps, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		op_ra(ps, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		op_rb(ps, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		op_rr(ps, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		op_rra(ps, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		op_rrb(ps, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		op_rrr(ps, 0);
	else
		badinput(ps, line);
}

void	checker(t_ps *ps)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		operator(ps, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*array;

	if (argc < 2)
		ft_error("Error\n");
	array = arrayinit(argc, argv);
	if (!array)
		ft_error("Error\n");
	ps.total = ft_wordcount(array, ' ');
	paramcheck(array, &ps);
	to_index(&ps);
	checker(&ps);
	if (checksort(&ps) && ps.size_a == ps.total && ps.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free (array);
	free (ps.stack_a);
	free (ps.stack_b);
	return (0);
}
