/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_optimise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:04:16 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 17:28:20 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_stacks *stacks, char *op)
{
	t_list	*node;
	char	*content;

	content = ft_strdup(op);
	if (!content)
		return ;
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return;
	}
	node->next = NULL;
	ft_lstadd_back(&stacks->operations, node);
}

void	optimise_ops(t_stacks *stacks)
{
	merge_rr(stacks->operations);
	merge_rrr(stacks->operations);
	rm_redundancy(&stacks->operations);
}

void	print_ops(t_list *ops)
{
	t_list	*current;

	current = ops;
	while (current)
	{
		if (current->content)
			ft_putstr_fd(current->content, 1);
		current = current->next;
	}
}
