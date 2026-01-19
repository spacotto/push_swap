/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:09:12 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 22:52:05 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	istarget(t_list *node, int min, int max, t_biggest *b)
{
	if (node->index < min || node->index > max)
		return (0);
	if (b && b->p1 && node == b->p1)
		return (0);
	if (b && b->p2 && node == b->p2)
		return (0);
	if (b && b->p3 && node == b->p3)
		return (0);
	return (1);
}

int	find_distance(t_list *stack, t_list *target)
{
	int	size;
	int	position;

	size = ft_lstsize(stack);
	position = ft_lstpos(stack, target);
	if (position <= size / 2)
		return (position);
	else
		return (size - position);
}

t_list	*find_best_target(t_list *stack, t_chunk *chunk, t_biggest *b)
{
	t_list		*current;
	t_list		*best;
	int			min_distance;
	int			distance;

	if (!stack)
		return (NULL);
	current = stack;
	best = NULL;
	min_distance = ft_lstsize(stack) + 1;  // Start with impossible value
	while (current)
	{
		if (istarget(current, chunk->min, chunk->max, b))
		{
			distance = find_distance(stack, current);
			if (distance < min_distance)
			{
				min_distance = distance;
				best = current;
			}
		}
		current = current->next;
	}
	return (best);
}
