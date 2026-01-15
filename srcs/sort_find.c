/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:26:13 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 21:50:36 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *find_smallest(t_list *stack)
{
    t_list  *smallest;
    t_list  *current;

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

    if (!stack)
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
