/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 12:32:10 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stacks *stacks, int ac, char **av)
{
	make_stack(&stacks->stack_a, ac, av);
	if (stacks->stack_a)
	{
		if (ft_lstsort_check(stacks->stack_a) == 0)
		{
			if (ft_lstsize(stacks->stack_a) <= 3)
			{
				simple_sort(stacks, ft_lstsize(stacks->stack_a));
				print_ops(stacks->operations);
			}
			else if (ft_lstsize(stacks->stack_a) > 3)
			{
				range_sort(stacks);
				stacks->optimisation = optimise_ops(stacks->operations);
				print_ops(stacks->optimisation);
			}
		}
		return (1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	ft_memset(&stacks, 0, sizeof(t_stacks));
	if (ac > 1)
	{
		if (push_swap(&stacks, ac, av) == 1)
		{
			if (stacks.stack_a != NULL)
				ft_lstclear(&stacks.stack_a, del);
			if (stacks.operations != NULL)
				ft_lstclear(&stacks.operations, del);
			if (stacks.optimisation != NULL)
				ft_lstclear(&stacks.optimisation, del);
			return (0);
		}
		else
			return (-1);
	}
	return (0);
}
