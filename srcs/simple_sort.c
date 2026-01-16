/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:39:54 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 14:17:51 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	if (sort_check(stacks) == 0)
		ft_sa(stacks);
	else
		return ;
}

void	sort_three(t_stacks *stacks)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = *(int *)stacks->stack_a->content;
	n2 = *(int *)stacks->stack_a->next->content;
	n3 = *(int *)stacks->stack_a->next->next->content;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(stacks);
	else if (n1 > n2 && n2 > n3)
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_ra(stacks);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_rra(stacks);
}

void	sort_four(t_stacks *stacks)
{
	t_list	*smallest;
	int		rotation;

	assign_index(stacks->stack_a);
	smallest = find_smallest(stacks->stack_a);
	ft_pb(stacks);
	smallest = find_smallest(stacks->stack_a);
	if (stacks->stack_a != smallest)
		move_to_top_a(stacks, smallest);
	if (stacks->stack_a != smallest)
		move_to_top_a(stacks, smallest);
	ft_pb(stacks);
	if (sort_check(stacks) == 0)
		ft_sa(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}

void	sort_five(t_stacks *stacks)
{
	t_list	*smallest;

	assign_index(stacks->stack_a);
	smallest = find_smallest(stacks->stack_a);
	if (stacks->stack_a != smallest)
		move_to_top_a(stacks, smallest);
	ft_pb(stacks);
	smallest = find_smallest(stacks->stack_a);
	if (stacks->stack_a != smallest)
		move_to_top_a(stacks, smallest);
	ft_pb(stacks);
	sort_three(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}
