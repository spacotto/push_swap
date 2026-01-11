/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/11 19:55:18 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_tokens(t_stacks *stacks, char *s)
{
	char	*token;
	int		*number;
	t_list	*node;

	token = ft_strtok(s, " ");
	if (!token)
			return;
	number = malloc(1 * sizeof(int));
	*number = ft_atoi(token);
	node = ft_lstnew(number);
	ft_lstadd_back(&stacks->stack_a, node);
	while (token != NULL)
	{
		token = ft_strtok(NULL, " ");
		if (!token)
				break;
		*number = ft_atoi(token);
		node = ft_lstnew(number);
		ft_lstadd_back(&stacks->stack_a, node);
	}
}

static void push_swap(t_stacks *stacks)
{
		int *fuck_you = stacks->stack_a->content;
	// if unsure create tmp pointers to access list to avoid pushing your pointer
	// like a dumbass and losing your first member
	while (stacks->stack_a)
	{
		ft_printf("%i ", *fuck_you);
		stacks->stack_a = stacks->stack_a->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;

	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			i++;
			get_tokens(&stacks, av[i]);
		}
		push_swap(&stacks);
	}
	return (0);
}
