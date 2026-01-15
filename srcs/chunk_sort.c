/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 22:54:37 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stacks *stacks)
{
	t_list	*biggest;

	assign_index(stacks->stack_a);
	chunk_presort(stacks);
	while (stacks->stack_b)
	{
		biggest = find_biggest(stacks->stack_a);
		cost_to_top_b(stacks, biggest);
		ft_pa(stacks);
	}
}
