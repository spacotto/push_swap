/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/23 11:34:29 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_range(int stack_size)
{
	int	range;
		
	if (stack_size <= 5)
		range = 1;
	else if (stack_size <= 100)
		range = 20;
	else
		range = 30;
	return (range);
}

static int	is_target(t_list *current, int range, t_biggest *b)
{
	if (current->index >= range)
		return (0);
	if (b->first && current == b->first)
		return (0);
	if (b->second && current == b->second)
		return (0);
	if (b->third && current == b->third)
		return (0);
	return (1);
}

void    chunk_presort(t_stacks *stacks)
{
	int			stack_size;
	int			range;
	int			pushed;
	t_list		*current;
	t_biggest	b;

	stack_size = ft_lstsize(stacks->stack_a);
	range = choose_range(stack_size);
	pushed = 0;
	b.first = find_biggest(stacks->stack_a);
	b.second = find_second_biggest(stacks->stack_a);
	b.third = find_third_biggest(stacks->stack_a);
	while (stack_size > 3)
	{
		if (is_target(stacks->stack_a, range, &b) == 1)
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
