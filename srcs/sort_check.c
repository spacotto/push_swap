/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:52:55 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/13 17:07:13 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stacks *stacks)
{
	t_list	*current;
	int		current_value;
	int		next_value;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return (1);
	current = stacks->stack_a;
	while (current->next)
	{
		current_value = *(int *)current->content;
		next_value = *(int *)current->next->content;
		if (current_value > next_value)
			return (0);
		current = current->next;
	}
	return (1);
}
