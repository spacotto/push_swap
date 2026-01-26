/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 17:06:23 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_range(int stack_size)
{
	int	range;

	if (stack_size <= 5)
		range = 3;
	else if (stack_size <= 100)
		range = 20;
	else
		range = 30;
	return (range);
}

static int	is_target(t_list *current, int range, int max_range)
{
	if (current->index >= range)
		return (0);
	if (current->index > max_range)
		return (0);
	return (1);
}

void	range_presort(t_stacks *stacks)
{
	int	stack_size;
	int	max_range;
	int	range;
	int	pushed;

	stack_size = ft_lstsize(stacks->stack_a);
	max_range = stack_size - 4;
	range = choose_range(stack_size);
	pushed = 0;
	while (stack_size > 3)
	{
		if (is_target(stacks->stack_a, range, max_range) == 1)
		{
			ft_pb(stacks);
			if (stacks->stack_b->index < pushed)
				ft_rb(stacks);
			pushed++;
			range++;
		}
		else
			ft_ra(stacks);
		stack_size = ft_lstsize(stacks->stack_a);
	}
}
