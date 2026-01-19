/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 22:55:19 by spacotto         ###   ########.fr       */
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

static void	build_chunk(t_stacks *stacks, t_chunk *chunk, t_biggest *b)
{
	t_list		*target;
	int			mid;

	mid = chunk->min + (chunk->max - chunk->min) / 2;
	while (1)
	{
		b->p1 = NULL;
		b->p2 = NULL;
		b->p3 = NULL;
		if (ft_lstsize(stacks->stack_a) > 3)
		{
			b->p1 = find_biggest(stacks->stack_a);
			b->p2 = find_second_biggest(stacks->stack_a);
			b->p3 = find_third_biggest(stacks->stack_a);
		}
		target = find_best_target(stacks->stack_a, chunk, b);
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
	t_biggest	biggest;

	chunk.stack_size = ft_lstsize(stacks->stack_a);
	chunk.size = choose_chunk_size(chunk.stack_size);
	chunk.min = 0;
	chunk.max = chunk.size - 1;
	while (chunk.stack_size > 3)
	{
		build_chunk(stacks, &chunk, &biggest);
		chunk.min += chunk.size;
		chunk.max += chunk.size;
		chunk.stack_size = ft_lstsize(stacks->stack_a);
	}
}
