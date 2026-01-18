/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 18:00:45 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	if (sort_check(stacks) == 0)
	{
		if (ft_lstsize(stacks->stack_a) <= 5)
			simple_sort(stacks);
		else
			chunk_sort(stacks);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;

	i = 1;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.operations = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			get_tokens(&stacks, av[i]);
			i++;
		}
		push_swap(&stacks);
		if (stacks.stack_a == NULL)
			optimise_ops(&stacks);
		print_ops(&stacks);
//		ft_lstclear(&stacks.operations, del);
		ft_lstclear(&stacks.stack_a, del);
	}
	return (0);
}
