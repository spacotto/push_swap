/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:17:08 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/25 18:17:49 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = ft_lstlast(*stack);
	*stack = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ft_ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
}

void	ft_rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
}

void	ft_rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
}
