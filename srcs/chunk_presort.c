/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 23:54:12 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_disorder(t_list *stack)
{
	t_list	*current;
	int		inversions;

	inversions = 0;
	current = stack;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			inversions++;
		current = current->next;
	}
	return (inversions);
}

static int	choose_chunk_size(int stack_size)
{
	int	chunk_size;

	if (stack_size <= 5)
		chunk_size = 1;
	else if (stack_size <= 100)
		chunk_size = 33;
	else
		chunk_size = 66;
	return (chunk_size);
}


static void    build_chunk(t_stacks *stacks, t_chunk *chunk, t_biggest *b)
{
    t_list        *target;
    int            mid;

    mid = chunk->min + (chunk->max - chunk->min) / 2;
    while (1)
    {
        if (ft_lstsize(stacks->stack_a) <= 3)
            break;
        b->p1 = find_biggest(stacks->stack_a);
        b->p2 = find_second_biggest(stacks->stack_a);
        b->p3 = find_third_biggest(stacks->stack_a);
        target = find_best_target(stacks->stack_a, chunk, b);
        if (!target)
            break;
        move_to_top_a(stacks, target);
        ft_pb(stacks);
        if (stacks->stack_b && stacks->stack_b->index < mid)
            ft_rb(stacks);
    }
}

void    chunk_presort(t_stacks *stacks)
{
    t_chunk		chunk;
    t_biggest	biggest;
	int			strict_max;

    chunk.size = choose_chunk_size(ft_lstsize(stacks->stack_a));
    chunk.min = 0;
    chunk.max = chunk.size - 1;
    strict_max = ft_lstsize(stacks->stack_a) - 4;
    while (ft_lstsize(stacks->stack_a) > 3)
    {
        if (chunk.max > strict_max)
            chunk.max = strict_max;
        build_chunk(stacks, &chunk, &biggest);
        chunk.min += chunk.size;
        chunk.max = chunk.min + chunk.size - 1;
    }
}
