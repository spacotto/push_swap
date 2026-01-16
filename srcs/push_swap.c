/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:42 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_tokens(t_stacks *stacks, char *s)
{
	char	*token;
	int		*number;
	t_list	*node;

	token = ft_strtok(s, " ");
	while (token != NULL)
	{
		number = malloc(1 * sizeof(int));
		if (!number)
			return ;
		*number = ft_atoi(token);
		node = ft_lstnew(number);
		if (!node)
		{
			free(number);
			return ;
		}
		ft_lstadd_back(&stacks->stack_a, node);
		token = ft_strtok(NULL, " ");
	}
}

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

static void	print_operations(t_stacks *stacks)
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
		optimize_rr(&stacks);
		optimize_rrr(&stacks);
		print_operations(&stacks);
//		ft_lstclear(&stacks.operations, del); // fix free
		ft_lstclear(&stacks.stack_a, del);
	}
	return (0);
}
