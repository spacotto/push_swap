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

static void	calculate_disorder(t_list *stack, t_chunk *chunk)
{
	t_list	*current;

	chunk->stack_disorder = 0;
	current = stack;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			chunk->stack_disorder++;
		current = current->next;
	}
	return (chunk->stack_disorder);
}

static void	choose_chunk_size(t_list *stack, t_chunk *chunk)
{
	chunk->stack_size = ft_lstsize(stack);
	calculate_disorder(stack, chunk);
	chunk->max_disorder = chunk->stack_size - 1;
	if (chunk->stack_size <= 5)
		chunk->size = 1;
	else if (chunk->stack_size > 5 && chunk->stack_size <= 100)
	{
		chunk->size = 33;
	}
	else
	{
		if (chunk->disorder < chunk->max_disorder * 0.33)
			chunk->size = 75;  // Low disorder (0-33%)
		else if (chunk->disorder < chunk->max_disorder * 0.66)
			chunk->size = 68;  // Medium disorder (33-66%)
		else
			chunk->size = 60;  // High disorder (66-100%)
	}
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

    choose_chunk_size(stacks->stack_a, &chunk);
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
