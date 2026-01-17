/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/17 21:35:23 by spacotto         ###   ########.fr       */
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

void	add_operation(t_stacks *stacks, char *op)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	new_node->content = op;
	new_node->next = NULL;
	if (!stacks->operations)
		stacks->operations = new_node;
	else
	{
		current = stacks->operations;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

static void	optimise_ops(t_stacks *stacks)
{
	merge_rr(stacks);
	merge_rrr(stacks);
	rm_ra_rra(stacks);
	rm_rb_rrb(stacks);
}

static void	print_ops(t_stacks *stacks)
{
	t_list	*current;

	current = stacks->operations;
	while (current)
	{
		ft_putstr_fd(current->content, 1);
		current = current->next;
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
		optimise_ops(&stacks);
		print_ops(&stacks);
//		ft_lstclear(&stacks.operations, del); // fix free
		ft_lstclear(&stacks.stack_a, del);
	}
	return (0);
}
