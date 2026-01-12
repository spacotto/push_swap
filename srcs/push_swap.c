/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/12 17:44:46 by spacotto         ###   ########.fr       */
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
			return;
		*number = ft_atoi(token);
		node = ft_lstnew(number);
		if (!node)
		{
			free(number);
			return;
		}
		ft_lstadd_back(&stacks->stack_a, node);
		token = ft_strtok(NULL, " ");
	}
}

static void push_swap(t_stacks *stacks)
{
	t_list	*current_a = stacks->stack_a;
	t_list	*current_b = stacks->stack_b;
	int		*number;

	ft_printf("\nSTACK A\n");
	while (current_a)
	{
		number = current_a->content;
		ft_printf("%i\n", *number);
		current_a = current_a->next;
	}
	ft_printf("\nSTACK B\n");
	while (current_b)
	{
		number = current_b->content;
		ft_printf("%i\n", *number);
		current_b = current_b->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;

	i = 1;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			get_tokens(&stacks, av[i]);
			i++;
		}
		ft_pb(&stacks);
		ft_pb(&stacks);
		ft_pb(&stacks);
		ft_rr(&stacks);
		push_swap(&stacks);
	}
	return (0);
}
