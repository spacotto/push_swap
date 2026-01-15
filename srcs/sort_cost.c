/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:31:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 19:00:55 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_top_a(t_stacks *stacks, t_list *target)
{
	int	size;
	int	position;
	int	rotation;

	size = ft_lstsize(stacks->stack_a);
	position = ft_lstpos(stacks->stack_a, target);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rra(stack);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_ra(stack);
	}
}

void	cost_to_top_b(t_stacks *stacks, t_list *target)
{
	int	size;
	int	position;
	int	rotation;

	size = ft_lstsize(stack);
	position = ft_lstpos(stack, target);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rrb(stack);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_rb(stack);
	}
}
