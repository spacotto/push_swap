/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:18:01 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/25 18:18:42 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	second_last = NULL;
	while (last_node->next)
	{
		second_last = last_node;
		last_node = last_node->next;
	}
	second_last->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	ft_rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
}

void	ft_rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
}

void	ft_rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
}
