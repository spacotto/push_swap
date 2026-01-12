/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:46:06 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/12 17:37:46 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	ft_swap((int *)first_node->content, (int *)second_node->content);
}

void	ft_sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
	ft_putstr_fd("ss\n", 1);
}
