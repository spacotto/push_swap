/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_to_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:14:59 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/17 19:15:06 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *cheapest_move_to_chunk(t_list *stack, int min, int max)
{
	t_list	*best_node;
	int		best_cost;
	int		cost;
	int		index;
	int		size;

	best_node = NULL;
	best_cost = INT_MAX;
	cost = 0;
	index = 0;
	size = ft_lstsize(stack);

	while (stack)
		{
			if (stack->index >= min && stack->index <= max)
				{
					if (index <= size / 2)
						cost = index; // ra
					else
						cost = size - index; // rra
					if (cost < best_cost)
						{
							best_cost = cost;
							best_node = stack;
							if (cost <= 1) // at 0 and 1 we can't get better
								return (best_node);
						}
				}
			stack = stack->next;
			index++;
		}
	return (best_node);
}
