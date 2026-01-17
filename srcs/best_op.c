/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/17 15:34:25 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_stacks *stacks, char *op)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	new_node->content = op;
	new_node->next = NULL;
	if (!stacks->operations)
		stacks->operations = new_node;
	else
	{
		current = stacks->operations;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	optimize_rr(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->content, "ra\n") == 0
			&& ft_strcmp(next->content, "rb\n") == 0)
		{
			current->content = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->content, "rb\n") == 0
			&& ft_strcmp(next->content, "ra\n") == 0)
		{
			current->content = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}

void	optimize_rrr(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->content, "rra\n") == 0
			&& ft_strcmp(next->content, "rrb\n") == 0)
		{
			current->content = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->content, "rrb\n") == 0
			&& ft_strcmp(next->content, "rra\n") == 0)
		{
			current->content = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}
