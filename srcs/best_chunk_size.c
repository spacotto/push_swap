/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_chunk_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:09:31 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 09:09:37 by spacotto         ###   ########.fr       */
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

int	choose_chunk_size(int stack_size)
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
