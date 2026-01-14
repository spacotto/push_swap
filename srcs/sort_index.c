/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:42:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 15:23:29 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_init(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		*(int *)(current->content) = -1;
		current = current->next;
	}
}

static t_list	*find_smallest(t_list *stack)
{
	t_list	*target;
	t_list	*current;
	int		current_content;
	int		target_content;

	target = stack;
	current = stack;
	current_content = *(int *)(current->content);
	target_content = *(int *)(target->content);
	while (current)
	{
		if (stack->index == 0 && (current_content < target_content))
			target = current;
		current = current->next;
	}
	return (target);
}

void	assign_index(t_list *stack)
{
	int		loop;

	loop = 0;
	index_init(stack);
	while (loop < ft_lstsize(stack))
	{
		find_smallest(stack);
		stack->index = loop;
		loop++;
	}
}
