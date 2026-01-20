/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 17:43:21 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	repeat_chunk_sort(t_stacks *stacks, int ac, char **av)
{
	int	counter;
	
	counter = 3;
	while (counter--)
	{
		ft_lstclear(&stacks->stack_a, del);
		stacks->stack_a = NULL;
		build_stack(stacks, ac, av);
		chunk_sort(stacks);
		optimise_ops(stacks);
		if (counter == 2)
			stacks->ops_s = ft_lstdup(stacks->operations);
		else if (counter == 1)
			stacks->ops_m = ft_lstdup(stacks->operations);
		else if (counter == 0)
			stacks->ops_l = ft_lstdup(stacks->operations);
	}
}

static void	best_chunk_sort(t_stacks *stacks, int ac, char **av)
{
	int	s;
	int	m;
	int	l;

	repeat_chunk_sort(stacks, ac, av);
	s = ft_lstsize(stacks->ops_s);
	m = ft_lstsize(stacks->ops_m);
	l = ft_lstsize(stacks->ops_l);
	if (s <= m && s <= l)
		print_ops(stacks->ops_s);
	else if (m <= s && m <= l)
		print_ops(stacks->ops_m);
	else if (l <= s && l <= m)
		print_ops(stacks->ops_l);
}

void	push_swap(t_stacks *stacks, int ac, char **av)
{
	build_stack(stacks, ac, av);
	if (sort_check(stacks) == 0)
	{
		if (ft_lstsize(stacks->stack_a) == 2)
		{
			sort_two(stacks);
			print_ops(stacks->operations);
		}
		else if (ft_lstsize(stacks->stack_a) == 3)
		{
			sort_three(stacks);
			print_ops(stacks->operations);
		}
		else if (ft_lstsize(stacks->stack_a) <= 5)
		{
			chunk_sort(stacks);
			print_ops(stacks->operations);
		}
		else
			best_chunk_sort(stacks, ac, av);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.ops_s = NULL;
	stacks.ops_m = NULL;
	stacks.ops_l = NULL;
	if (ac > 1)
	{
		push_swap(&stacks, ac, av);
		ft_lstclear(&stacks.stack_a, del);
		ft_lstclear(&stacks.operations, del);
		ft_lstclear(&stacks.ops_s, del);
		ft_lstclear(&stacks.ops_m, del);
		ft_lstclear(&stacks.ops_l, del);
	}
	return (0);
}
