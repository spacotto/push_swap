/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:26:13 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:05 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest(t_list *stack)
{
	t_list	*smallest;
	t_list	*current;

	if (!stack)
		return (NULL);
	smallest = stack;
	current = stack->next;
	while (current)
	{
		if (current->index < smallest->index)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;
	t_list	*current;

	if (!stack || !stack->next)
		return (NULL);
	biggest = NULL;
	current = stack;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_list	*find_second_biggest(t_list *stack)
{
	t_list	*biggest;
	t_list	*second;
	t_list	*current;

	if (!stack || !stack->next)
		return (NULL);
	biggest = find_biggest(stack);
	second = NULL;
	current = stack;
	while (current)
	{
		if (current != biggest)
		{
			if (!second || current->index > second->index)
				second = current;
		}
		current = current->next;
	}
	return (second);
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
