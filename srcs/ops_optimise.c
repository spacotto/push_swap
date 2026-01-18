/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_optimise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:04:16 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 20:05:50 by spacotto         ###   ########.fr       */
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

static void	check_ops(t_list  *cmp1, t_list  *cmp2)
{
	if (merge_rr(cmp1, cmp2) == 1)
		return ;
	else if (merge_rrr(cmp1, cmp2) == 1)
		return ;
	else if (rm_ra_rra(cmp1, cmp2) == 1)
		return ;
	else if (rm_rb_rrb(cmp1, cmp2) == 1)
		return ;
	else
		return ;
}

void	optimise_ops(t_stacks *stacks)
{
	t_list  *cmp1;
	t_list  *cmp2;

	cmp1 = stacks->operations;
	cmp2 = cmp1->next;
	while (cmp1 && cmp2)
	{
		if (cmp1->content && cmp2->content)
		{
			check_ops(cmp1, cmp2);
			cmp1 = cmp2->next;
			if (cmp1->next)
				cmp2 = cmp1->next;
			else
				break ;
		}
		else if (!cmp1->content)
		{
			cmp1 = cmp2;
			cmp2 = cmp1->next;
		}
		else if (!cmp2->content)
			cmp2 = cmp2->next;
	}
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
