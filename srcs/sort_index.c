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

static void	index_init(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

static t_list	*find_index(t_list *stack)
{
	t_list	*target;
	t_list	*current;

	target = NULL;
	current = stack;
	index_init(stack);
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

	loop = 0;
	while (loop < ft_lstsize(stack))
	{
		smallest = find_index(stack);
		smallest->index = loop;
		loop++;
	}
}
