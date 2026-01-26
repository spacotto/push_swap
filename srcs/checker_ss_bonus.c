/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ss_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:16:28 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 14:16:57 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_sa_bonus(t_stacks *stacks)
{
	swap(&stacks->stack_a);
}

void	ft_sb_bonus(t_stacks *stacks)
{
	swap(&stacks->stack_b);
}

void	ft_ss_bonus(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
}
