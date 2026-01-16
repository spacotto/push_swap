/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:31:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 16:18:41 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_stacks *stacks, t_list *target)
{
	int	size;
	int	position;
	int	rotation;

	size = ft_lstsize(stacks->stack_a);
	position = ft_lstpos(stacks->stack_a, target);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rra(stacks);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_ra(stacks);
	}
}

void	move_to_top_b(t_stacks *stacks, t_list *target)
{
	int	size;
	int	position;
	int	rotation;

	size = ft_lstsize(stacks->stack_b);
	position = ft_lstpos(stacks->stack_b, target);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rrb(stacks);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_rb(stacks);
	}
}

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
