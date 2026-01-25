/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:11:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/25 18:16:22 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	ft_pb(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
}
