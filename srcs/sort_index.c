/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:42:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 15:55:11 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_smallest_unindexed(t_list *stack)
{
	t_list	*target;
	t_list	*current;

	target = NULL;
	current = stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (!target
				|| *(int *)(current->content) < *(int *)(target->content))
				target = current;
		}
		current = current->next;
	}
	return (target);
}

void	assign_index(t_list *stack)
{
	int		loop;
	t_list	*smallest;
	t_list	*current;

	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	loop = 0;
	while (loop < ft_lstsize(stack))
	{
		smallest = find_smallest_unindexed(stack);
		smallest->index = loop;
		loop++;
	}
}
