/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:09 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 18:35:21 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int stack_size)
{
	int	chunk_size;
	
	if (stack_size <= 16)
		chunk_size = 4;
	else if (stack_size <= 100)
 		chunk_size = 20;
	else
		chunk_size = 45;
	return (chunk_size);
}

static void	push_or_rotate(t_stacks *stacks)
{}

void	chunk_presort(t_stacks *stacks)
{
	int	stack_size;
	int	chunk_size;
	int	chunks;

	stack_size = ft_lstsize(stacks->stack_a);
	chunk_size = chunk_size(stack_size);
	chunks = stack_size / chunk_size;
	while (chunks--)
	{
		while (stack_size > 3)
		{
			push_or_rotate(stacks, chunk_size);
			stack_size = ft_lstsize(stacks->stack_a);
		}
	}
}
