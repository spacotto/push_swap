/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:46:06 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/12 17:21:39 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	nodeswap(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
}

void	ft_sa(t_stacks *stacks)
{
	nodeswap(&stacks->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stacks *stacks)
{
	nodeswap(&stacks->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stacks *stacks)
{
	nodeswap(&stacks->stack_a);
	nodeswap(&stacks->stack_b);
	ft_putstr_fd("ss\n", 1);
}
