/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/22 18:46:53 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stacks, int ac, char **av)
{
	build_stack(stacks, ac, av);
	if (sort_check(stacks) == 0)
	{
		if (ft_lstsize(stacks->stack_a) == 2)
		{
			ft_sa(stacks);
			print_ops(stacks->operations);
		}
		else if (ft_lstsize(stacks->stack_a) == 3)
		{
			sort_three(stacks);
			print_ops(stacks->operations);
		}
		else if (ft_lstsize(stacks->stack_a) > 3)
		{
			chunk_sort(stacks);
			stacks->optimisation = optimise_ops(stacks->operations);
			print_ops(stacks->optimisation);
		}
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	ft_memset(&stacks, 0, sizeof(t_stacks));
	if (ac > 1)
	{
		push_swap(&stacks, ac, av);
		if (stacks.stack_a != NULL)
			ft_lstclear(&stacks.stack_a, del);
		if (stacks.operations != NULL)
			ft_lstclear(&stacks.operations, del);
		if (stacks.optimisation != NULL)
			ft_lstclear(&stacks.optimisation, del);
	}
	return (0);
}
