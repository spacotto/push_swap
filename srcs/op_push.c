/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:46:18 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/12 17:39:31 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	node_to_push->next = *dst;
	*dst = node_to_push;
}

void	ft_pa(t_stacks *stacks)
{
	push(&stacks->stack_a, &stacks->stack_b);
	add_operation(&stacks->operations, "pa\n");
}

void	ft_pb(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
	add_operation(&stacks->operations, "pb\n");
}
