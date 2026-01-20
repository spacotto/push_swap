/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 17:33:33 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_sizes_100(t_chunk *chunk, int counter)
{
	if (counter == 1)
	{
		chunk->size = 10;
		counter++;
	}
	if (counter == 2)
	{
		chunk->size = 33;
		counter++;
	}
	if (counter == 3)
		chunk->size = 66;
}

static void	chunk_sizes_500(t_chunk *chunk, int counter)
{
	if (counter == 1)
	{
		chunk->size = 60;
		counter++;
	}
	if (counter == 2)
	{
		chunk->size = 65;
		counter++;
	}
	if (counter == 3)
		chunk->size = 70;
}

static void	choose_chunk_size(t_list *stack, t_chunk *chunk)
{
	static int	counter = 1;

	chunk->stack_size = ft_lstsize(stack);
	if (chunk->stack_size <= 5)
		chunk->size = 1;
	else if (chunk->stack_size > 5 && chunk->stack_size <= 100)
		chunk_sizes_100(chunk, counter);
	else
		chunk_sizes_500(chunk, counter);
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
