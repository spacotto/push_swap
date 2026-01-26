/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:45:34 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 14:23:49 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*make_token(char *token)
{
	int		*number;
	t_list	*new_node;
	
	number = ft_calloc(1, sizeof(int));
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

void	make_stack(t_list **stack, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
		{
			error_msg();
			if (stack != NULL)
				ft_lstclear(stack, del);
			return ;
		}	
		add_token(stack, av[i]);
		if (!stack)
			return ;
		i++;
    }
	has_dup(stack);
}
