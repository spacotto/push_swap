/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:46:39 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/12 17:59:57 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
	ft_putstr_fd("rr\n", 1);
}
