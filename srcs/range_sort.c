/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/24 18:29:19 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = *(int *)stacks->stack_a->content;
	n2 = *(int *)stacks->stack_a->next->content;
	n3 = *(int *)stacks->stack_a->next->next->content;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(stacks);
	else if (n1 > n2 && n2 > n3)
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_ra(stacks);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_rra(stacks);
}

void	simple_sort(t_stacks *stacks, int stack_size)
{
	if (stack_size == 2)
		ft_sa(stacks);
	if (stack_size == 3)
		sort_three(stacks);
}

static t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;
	t_list	*current;

	if (!stack || !stack->next)
		return (NULL);
	biggest = stack;
	current = stack->next;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	range_sort(t_stacks *stacks)
{
	t_list	*biggest;

	assign_index(stacks->stack_a);
	range_presort(stacks);
	simple_sort(stacks, ft_lstsize(stacks->stack_a));
	biggest = NULL;
	while (stacks->stack_b)
	{
		biggest = find_biggest(stacks->stack_b);
		move_to_top_b(stacks, biggest);
		ft_pa(stacks);
	}
}
