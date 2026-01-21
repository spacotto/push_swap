/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_optimise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:04:16 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/21 22:26:20 by spacotto         ###   ########.fr       */
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

static void	just_copy(t_list *node_to_copy, t_list **target_list)
{
	t_list	*node_copy;

	node_copy = ft_lstdup(node_to_copy);
	if (!node_copy)
		return ;
	ft_lstadd_back(target_list, node_copy);
}

t_list    *optimise_ops(t_list *ops)
{
    t_list    *current;
    t_list    *new_list;

    if (!ops)
        return (NULL);
    new_list = NULL;
    current = ops;
    while (current && current->next)
    {
        if (isrr(current->content, current->next->content))
        {
            merge_rr(&new_list);
            current = current->next;
        }
        else if (isrrr(current->content, current->next->content))
        {
            merge_rrr(&new_list);
            current = current->next;
        }
        else if (redundancy(current, current->next))
            current = current->next;
        else
            just_copy(current, &new_list);
        current = current->next;
    }
    if (current)
        just_copy(current, &new_list);
    return (new_list);
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
