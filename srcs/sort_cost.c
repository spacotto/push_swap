/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:31:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 12:35:16 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_top(t_stacks *stacks, t_list *smallest)
{
	int	position;
	int	size;
	int	rotation;

	position = ft_lstpos(stacks->stack_a, smallest);
	size = ft_lstsize(stacks->stack_a);
	if (position > size / 2)
	{
		rotation = size - position;
		while (rotation--)
			ft_rra(stacks);
	}
	else
	{
		rotation = position;
		while (rotation--)
			ft_ra(stacks);
	}
}
