/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:32:55 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/24 21:34:10 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *token)
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

int	is_int(char *token)
{
	if (ft_atol(token) < INT_MIN) 
		return (0);
	if (ft_atol(token) > INT_MAX)
		return (0);
	return (1);
}

void	has_dup(t_list **stack)
{
	t_list	*current;
	t_list	*cmp;
	int		current_content;
	int		cmp_content;

	current = *stack;
	while (current)
	{
		current_content = *(int *)current->content;
		cmp = current->next;
		while (cmp)
		{
			cmp_content = *(int *)cmp->content;
			if (current_content == cmp_content)
			{	
				error_msg();
				if (stack != NULL)
					ft_lstclear(stack, del);
				return ;
			}
			cmp = cmp->next;
		}
		current = current->next;
	}
}
