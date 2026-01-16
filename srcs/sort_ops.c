/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:31:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 15:48:05 by spacotto         ###   ########.fr       */
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
	t_ops	*new_node;
	t_ops	*current;

	new_node = malloc(sizeof(t_ops));
	if (!new_node)
		return;
	new_node->operation = op;
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
	t_ops	*current;
	t_ops	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->operation, "ra\n") == 0
			&& ft_strcmp(next->operation, "rb\n") == 0)
		{
			current->operation = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->operation, "rb\n") == 0
			&& ft_strcmp(next->operation, "ra\n") == 0)
		{
			current->operation = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}

void	optimize_rrr(t_stacks *stacks)
{
	t_ops	*current;
	t_ops	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->operation, "rra\n") == 0
			&& ft_strcmp(next->operation, "rrb\n") == 0)
		{
			current->operation = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->operation, "rrb\n") == 0
			&& ft_strcmp(next->operation, "rra\n") == 0)
		{
			current->operation = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}
