/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 18:37:57 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stacks *stacks)
{
	assign_index(stacks->stack_a);
	chunk_presort(stacks);
	while (sort_check(stacks) == 0)
	{
		find_biggest(stacks->stack_a);
	}
}
