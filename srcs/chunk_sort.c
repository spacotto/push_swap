/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 17:56:08 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk_size(int stack_size)
{
	int	chunk_size;

	if (stack_size <= 16)
		chunk_size = 4;
	else if (stack_size <= 100)
		chunk_size = 30;
	else
		chunk_size = 166;
	return (chunk_size);
}

static void	build_chunk(t_stacks *stacks, int chunk_min, int chunk_max)
{
	t_list	*target;
	int		mid;

	mid = chunk_min + (chunk_max - chunk_min) / 2;
	while (1)
		{
			target = find_best_target(stacks->stack_a, chunk_min, chunk_max);
			if (!target)
				break;
			move_to_top_a(stacks, target);
			ft_pb(stacks);
			if (stacks->stack_b && stacks->stack_b->index < mid)
				{
					ft_rb(stacks);
				}
		}
}

static void	chunk_presort(t_stacks *stacks)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	total_size;

	total_size = ft_lstsize(stacks->stack_a);
	chunk_size = choose_chunk_size(total_size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (stacks->stack_a && total_size > 3)
	{
		build_chunk(stacks, chunk_min, chunk_max);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
		total_size = ft_lstsize(stacks->stack_a);
	}
}

static void	chunk_finalsort(t_stacks *stacks)
{
	t_list	*biggest;
	t_list	*second_biggest;

	while (stacks->stack_b)
	{
		biggest = find_biggest(stacks->stack_b);
		second_biggest = find_second_biggest(stacks->stack_b);
		if (second_biggest && (find_distance(stacks->stack_b, second_biggest) < 
			find_distance(stacks->stack_b, biggest)))
		{
			move_to_top_b(stacks, second_biggest);
			ft_pa(stacks);
			biggest = find_biggest(stacks->stack_b);
			move_to_top_b(stacks, biggest);
			ft_pa(stacks);
			ft_sa(stacks);
		}
		else
		{
			move_to_top_b(stacks, biggest);
			ft_pa(stacks);
		}
	}
}

void	chunk_sort(t_stacks *stacks)
{
	assign_index(stacks->stack_a);
	chunk_presort(stacks);
	chunk_finalsort(stacks);
}
