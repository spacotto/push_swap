/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/21 22:27:01 by spacotto         ###   ########.fr       */
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
		ft_lstclear(&stacks->operations, del);
		build_stack(stacks, ac, av);
		chunk_sort(stacks);
		if (counter == 2)
			stacks->ops_s = optimise_ops(stacks->operations);
		else if (counter == 1)
			stacks->ops_m = optimise_ops(stacks->operations);
		else if (counter == 0)
			stacks->ops_l = optimise_ops(stacks->operations);
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

	ft_memset(&stacks, 0, sizeof(t_stacks));
	if (ac > 1)
	{
		push_swap(&stacks, ac, av);
		if (stacks.stack_a != NULL)
			ft_lstclear(&stacks.stack_a, del);
		if (stacks.operations != NULL)
			ft_lstclear(&stacks.operations, del);
		if (stacks.ops_s != NULL)
			ft_lstclear(&stacks.ops_s, del);
		if (stacks.ops_m != NULL)
			ft_lstclear(&stacks.ops_m, del);
		if (stacks.ops_l != NULL)
			ft_lstclear(&stacks.ops_l, del);
	}
	return (0);
}
