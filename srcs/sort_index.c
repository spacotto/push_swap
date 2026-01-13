/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:42:36 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/13 18:47:50 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stacks *stacks)
{
	t_list	*current;
	t_list	*cmp;
	int		index;

	current = stacks->stack_a;
	while (current)
	{
		index = 0;
		cmp = stacks->stack_a;
		while (cmp)
		{
			if (*(int *)cmp->content < *(int *)current->content)
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
