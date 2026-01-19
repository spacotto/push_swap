/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 17:08:10 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk_size(int stack_size)
{
	int	chunk_size;

	if (stack_size <= 100)
		chunk_size = 33;
	else
		chunk_size = 60;
	return (chunk_size);
}

static void	build_chunk(t_stacks *stacks, int chunk_min, int chunk_max)
{
	t_list	*target;
	int		mid;

	mid = min + (max - min) / 2;
	while (1)
	{
		target = find_best_target(stacks->stack_a, min, max);
		if (!target)
			break;
		move_to_top_a(stacks, target);
		ft_pb(stacks);
		if (stacks->stack_b && stacks->stack_b->index < mid)
			ft_rb(stacks);
	}
}

void	chunk_presort(t_stacks *stacks)
{
	t_chunk		chunk;
	int			stack_size;

	stack_size = ft_lstsize(stacks->stack_a);
	chunk.size = choose_chunk_size(stack_size);
	chunk.min = 0;
	chunk.max = chunk.size - 1;
	while (stack_size > 3)
	{
		build_chunk(stacks, chunk.min, chunk.max);
		chunk.min += chunk.size;
		chunk.max += chunk.size;
		stack_size = ft_lstsize(stacks->stack_a);
	}
}
