/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/23 11:34:56 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;
	t_list	*current;

	if (!stack || !stack->next)
		return (NULL);
	biggest = stack;
	current = stack->next;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	chunk_sort(t_stacks *stacks)
{
	t_list	*biggest;

	assign_index(stacks->stack_a);
	chunk_presort(stacks);
	sort_three(stacks);
	biggest = NULL;
	while (stacks->stack_b)
	{
		biggest = find_biggest(stacks->stack_b);
		move_to_top_b(stacks, biggest);
		ft_pa(stacks);
	}
}
