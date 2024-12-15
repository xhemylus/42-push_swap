/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:45:11 by abollen           #+#    #+#             */
/*   Updated: 2022/03/02 17:06:10 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_ps
{
	int	total;
	int	size_a;
	int	size_b;
	int	*stack_a;
	int	*stack_b;
	int	bucket_size;
	int	bucket_limit[2];
	int	*temp;
}		t_ps;
void	to_index(t_ps *ps);

/*-- push_swap.c --*/
char	*arrayinit(int argc, char **argv);
void	checkint(char *array);

/*-- op_swap.c --*/
void	op_sa(t_ps *ps, int echo);
void	op_sb(t_ps *ps, int echo);
void	op_ss(t_ps *ps, int echo);
/*-- op_rotate.c --*/
void	op_ra(t_ps *ps, int echo);
void	op_rb(t_ps *ps, int echo);
void	op_rr(t_ps *ps, int echo);
/*-- op_reverse.c --*/
void	op_rra(t_ps *ps, int echo);
void	op_rrb(t_ps *ps, int echo);
void	op_rrr(t_ps *ps, int echo);
/*-- op_push.c --*/
void	op_pa(t_ps *ps, int echo);
void	op_pb(t_ps *ps, int echo);
/*-- utils.c --*/
void	autorotate_a(t_ps *ps, int to_find);
void	autorotate_b(t_ps *ps, int to_find);
int		countrotate_b(t_ps *ps, int to_find);
int		countrotate_a(t_ps *ps, int to_find);
int		checksort(t_ps *ps);
/*-- check.c --*/
int		ft_isnum(char *str);
void	checkdoublon(t_ps *ps);
void	stack_init(char *array, t_ps *ps);
void	paramcheck(char *argv, t_ps *ps);
int		ft_sqrt(int nb);
/*-- sort.c --*/
void	sort_three(t_ps *ps);
void	sorthandler(t_ps *ps);
void	smallsort(t_ps *ps);
void	bucketsort_b(t_ps *ps);
void	insert(t_ps *ps);
/*-- sort2.c --*/
int		getminmove_b(t_ps *ps);
int		findspot(t_ps *ps, int to_place);
int		bucketinit(t_ps *ps);
/*-- multirotate.c --*/
int		direction_a(t_ps *ps, int to_find);
int		direction_b(t_ps *ps, int to_find);
void	multirotate(t_ps *ps, int to_finda, int to_findb);
char	*arrayinit(int argc, char **argv);
#endif