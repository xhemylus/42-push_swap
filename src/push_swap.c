/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:17 by abollen           #+#    #+#             */
/*   Updated: 2022/02/01 16:43:14 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*array;

	if (argc < 2)
		return (1);
	array = arrayinit(argc, argv);
	if (!array)
		ft_error("Error\n");
	ps.total = ft_wordcount(array, ' ');
	paramcheck(array, &ps);
	if (!checksort(&ps))
	{
		to_index(&ps);
		sorthandler(&ps);
	}
	free (array);
	free (ps.stack_a);
	free (ps.stack_b);
	return (0);
}
