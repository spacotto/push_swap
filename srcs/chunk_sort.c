/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 17:10:41 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(t_list *stack)
{
	int	stack_size;
	int	chunk_size;

	stack_size = ft_lstsize(stack);
	if (stack_size <= 16)
		chunk_size = 4;
	else if (stack_size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	return (chunk_size);
}

void	chunk_sort(t_stacks *stacks)
{
	assign_index(stacks->stack_a);
	chunk_size(stacks->stack_a);
}
