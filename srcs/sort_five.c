/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:49:42 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 15:56:44 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stacks *stacks, t_list *target)
{
	int	position;
	int	size;

	position = ft_lstchr(stacks->stack_a, target);
	size = ft_lstsize(stacks->stack_a);
	if (position > size / 2)
	{
		while (stacks->stack_a != target)
			ft_rra(stacks);
	}
	else
	{
		while (stacks->stack_a != target)
			ft_ra(stacks);
	}
}

void	sort_five(t_stacks *stacks)
{
	t_list	*target;

	target = find_smallest(stacks->stack_a);
	if (stacks->stack_a != target)
		move_to_top(stacks, target);
	ft_pb(stacks);
	target = find_smallest(stacks->stack_a);
	if (stacks->stack_a != target)
		move_to_top(stacks, target);
	ft_pb(stacks);
	sort_three(stacks);
	ft_pa(stacks);
	ft_pa(stacks);	
}
