/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:32:55 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/24 18:19:32 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	is_valid_number(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (ft_isdigit(token[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atol(token) < INT_MIN)
		return (0);
	if (ft_atol(token) > INT_MAX)
		return (0);
	return (1);	
}

static void	add_token(t_list **stack, char *s)
{
	char	*token;
	t_list	*node;

	token = ft_strtok(s, " ");
	while (token != NULL)
	{	
		if (is_valid_number(token))
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

int	has_dup(t_list *stack)
{
	t_list	*current;
	t_list	*cmp;
	int		current_val;
	int		cmp_val;

	current = stack;
	while (current)
	{
		current_val = *(int *)current->content;
		cmp = current->next;
		while (cmp)
		{
			cmp_val = *(int *)cmp->content;
			if (current_val == cmp_val)
				return (1);
			cmp = cmp->next;
		}
		current = current->next;
	}
	return (0);
}

void	make_stack(t_stacks *stacks, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{  
		add_token(&stacks->stack_a, av[i]);
		i++;
    }
	if (has_dup(stacks->stack_a) == 1)
	{
		error_msg();
		if (stacks->stack_a != NULL)
			ft_lstclear(&stacks->stack_a, del);
	}
}
