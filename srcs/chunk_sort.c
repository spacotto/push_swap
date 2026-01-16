/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 14:15:24 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk_size(int stack_size)
{
	int	chunk_size;

	if (stack_size <= 16)
		chunk_size = 4;
	else if (stack_size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	return (chunk_size);
}

static int	ischunk(int index, int chunk_min, int chunk_max)
{
	if (index >= chunk_min && index <= chunk_max)
		return (1);
	else
		return (0);
}

static void	build_chunk(t_stacks *stacks, int chunk_min, int chunk_max)
{
	int	pushed;

	pushed = 0;
	while (stacks->stack_a)
	{
		pushed = 0;
		while (pushed < chunk_max && stacks->stack_a)
		{
			if (ischunk(stacks->stack_a->index, chunk_min, chunk_max) == 1)
			{
				ft_pb(stacks);
				pushed++;
			}
			else
				ft_ra(stacks);
		}
	}
}

static void	chunk_presort(t_stacks *stacks)
{
	int	stack_size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	chunks;

	stack_size = ft_lstsize(stacks->stack_a);
	chunk_size = choose_chunk_size(stack_size);
	chunk_min = 0;
	chunk_max = chunk_size;
	chunks = stack_size / chunk_max;
	while (chunks--)
	{
		while (stack_size > 3)
		{
			build_chunk(stacks, chunk_min, chunk_max);
			stack_size = ft_lstsize(stacks->stack_a);
			chunk_min += chunk_size;
			chunk_max += chunk_size;
		}
	}
}

void	chunk_sort(t_stacks *stacks)
{
	t_list	*biggest;

	assign_index(stacks->stack_a);
	chunk_presort(stacks);
	while (stacks->stack_b)
	{
		biggest = find_biggest(stacks->stack_a);
		cost_to_top_b(stacks, biggest);
		ft_pa(stacks);
	}
}
