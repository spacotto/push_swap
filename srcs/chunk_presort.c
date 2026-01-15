/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:09 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 22:48:48 by spacotto         ###   ########.fr       */
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

void	chunk_presort(t_stacks *stacks)
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
