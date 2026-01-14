/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:50:40 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 17:54:34 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stacks *stacks, t_list *smallest)
{
	int	position;
	int	size;
	int	rotation;

	position = ft_lstchr(stacks->stack_a, smallest);
	size = ft_lstsize(stacks->stack_a);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rra(stacks);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_ra(stacks);
	}
}

void	sort_four(t_stacks *stacks)
{
	t_list	*smallest;

	smallest = find_smallest(stacks->stack_a);
	if (stacks->stack_a != smallest)
		move_to_top(stacks, smallest);
	ft_pb(stacks);
	smallest = find_smallest(stacks->stack_a);
	if (stacks->stack_a != smallest)
		move_to_top(stacks, smallest);
	ft_pb(stacks);
	if (sort_check(stacks) == 0)
		ft_sa(stacks);
	ft_pa(stacks);
	ft_pa(stacks);	
}
