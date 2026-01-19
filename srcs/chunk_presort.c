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

static void	build_chunk(t_stacks *stacks, int min, int max, t_biggest *b)
{
	t_list	*target;
	int		mid;

	mid = min + (max - min) / 2;
	while (1)
	{
		target = find_best_target(stacks->stack_a, min, max, b);
		if (!target)
			break;
		move_to_top_a(stacks, target);
		ft_pb(stacks);
		if (stacks->stack_b && stacks->stack_b->index < mid)
			ft_rb(stacks);
	}
}

void	chunk_presort(t_stacks *stacks, t_biggest *biggest)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	total_size;

	total_size = ft_lstsize(stacks->stack_a);
	chunk_size = choose_chunk_size(total_size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	biggest->p1 = find_biggest(stacks->stack_a);
	biggest->p2 = find_second_biggest(stacks->stack_a);
	biggest->p3 = find_third_biggest(stacks->stack_a);
	while (total_size > 3)
	{
		build_chunk(stacks, chunk_min, chunk_max, biggest);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
		total_size = ft_lstsize(stacks->stack_a);
	}
}
