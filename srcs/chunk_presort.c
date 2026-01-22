/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:08:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/22 19:20:18 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_chunk_size_100(t_stacks *stacks)
{
	int	chunk_size;

	chunk_size = 0;
	if (stacks->disorder > 0 && stacks->disorder <= 0.4)
		chunk_size = 50;
	if (stacks->disorder > 0.4 && stacks->disorder <= 0.42)
		chunk_size = 33;
	if (stacks->disorder > 0.42 && stacks->disorder <= 0.44)
		chunk_size = 25;
	if (stacks->disorder > 0.44 && stacks->disorder <= 0.46)
		chunk_size = 20;
	if (stacks->disorder > 0.46 && stacks->disorder <= 0.48)
		chunk_size = 22;
	if (stacks->disorder > 0.48 && stacks->disorder <= 0.5)
		chunk_size = 20;
	if (stacks->disorder > 0.5)
		chunk_size = 10;
	return (chunk_size);
}

static int	best_chunk_size_500(t_stacks *stacks)
{
	int	chunk_size;

	chunk_size = 0;
	if (stacks->disorder > 0 && stacks->disorder <= 0.2)
		chunk_size = 75;
	if (stacks->disorder > 0.2 && stacks->disorder <= 0.4)
		chunk_size = 70;
	if (stacks->disorder > 0.4 && stacks->disorder <= 0.6)
		chunk_size = 65;
	if (stacks->disorder > 0.6 && stacks->disorder <= 0.8)
		chunk_size = 60;
	if (stacks->disorder > 0.8 && stacks->disorder <= 1)
		chunk_size = 50;
	return (chunk_size);
}

static void	choose_chunk_size(t_stacks *stacks, t_chunk *chunk)
{
	chunk->stack_size = ft_lstsize(stacks->stack_a);
	stacks->disorder = ft_lst_disorder(stacks->stack_a);
	if (chunk->stack_size <= 5)
		chunk->size = 1;
	else if (chunk->stack_size <= 100)
		chunk->size = best_chunk_size_100(stacks);
	else
		chunk->size = best_chunk_size_500(stacks);
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

    choose_chunk_size(stacks, &chunk);
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
