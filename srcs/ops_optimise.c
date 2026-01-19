/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_optimise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:04:16 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 22:41:17 by spacotto         ###   ########.fr       */
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
	new_node->content = ft_strdup(op);
	if (!new_node->content)
		{
			free(new_node);
			return ;
		}
	new_node->next = NULL;
	ft_lstadd_back(&stacks, new_node)
}

void	optimise_ops(t_stacks *stacks)
{
	merge_rr(stacks->operations);
	merge_rrr(stacks->operations);
	rm_redundancy(&stacks->operations);
}

void	print_ops(t_stacks *stacks)
{
	t_list	*current;

	current = stacks->operations;
	while (current)
	{
		if (current->content)
			ft_putstr_fd(current->content, 1);
		current = current->next;
	}
}
