/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:46:50 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 17:29:52 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_one(t_stacks *stacks, t_biggest *biggest)
{
	move_to_top_b(stacks, biggest->p1);
	ft_pa(stacks);
}

static void	move_two(t_stacks *stacks, t_biggest *biggest)
{
	move_to_top_b(stacks, biggest->p2);
	ft_pa(stacks);
	move_one(stacks, biggest);
	sort_two(stacks);
}

void	chunk_sort(t_stacks *stacks)
{
	t_biggest	b;

	assign_index(stacks->stack_a);
	chunk_presort(stacks;
//	sort_three(stacks);
	while (stacks->stack_b)
	{
		b.p1 = find_biggest(stacks->stack_b);
		b.p2 = find_second_biggest(stacks->stack_b);
		b.d1 = find_distance(stacks->stack_b, b.p1);
		b.d2 = find_distance(stacks->stack_b, b.p2);
		if (b.p2 && (b.d2 < b.d1))
			move_two(stacks, &b);
		else
			move_one(stacks, &b);
	}
}
