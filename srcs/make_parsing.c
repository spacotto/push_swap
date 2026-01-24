/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:32:55 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/24 19:43:07 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-')
		i++;
	while (token[i])
	{
		if (ft_isdigit(token[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char *token)
{
	if (ft_atol(token) < INT_MAX) 
		return (0);
	if (ft_atol(token) > INT_MAX)
		return (0);
	return (1);
}

void	has_dup(t_list **stack)
{
	t_list	*current;
	t_list	*cmp;

	current = *stack;
	while (current)
	{
		cmp = current->next;
		while (cmp)
		{
			if (current->content == cmp->content)
			{	
				error_msg();
				if (stack != NULL)
					ft_lstclear(stack, del);
			}
			cmp = cmp->next;
		}
		current = current->next;
	}
}

static t_list	*make_token(char *token)
{
	int		*number;
	t_list	*new_node;
	
	number = malloc(1 * sizeof(int));
	if (!number)
		return (NULL);
	*number = ft_atol(token);
	new_node = ft_lstnew(number);
	if (!new_node)
	{
		free(number);
		return (NULL);
	}
	return (new_node);
}

static void	add_token(t_list **stack, char *s)
{
	char	*token;
	t_list	*node;

	token = ft_strtok(s, " ");
	while (token != NULL)
	{	
		if (is_number(token) == 1 && is_int(token) == 1)
		{
			node = make_token(token);
			ft_lstadd_back(stack, node);
			token = ft_strtok(NULL, " ");
		}
		else
		{
			error_msg();
			if (stack != NULL)
				ft_lstclear(stack, del);
			return ;
		}
	}
}

void	make_stack(t_stacks *stacks, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{  
		add_token(&stacks->stack_a, av[i]);
		if (!stacks->stack_a)
			return ;
		i++;
    }
	has_dup(&stacks->stack_a);
}
