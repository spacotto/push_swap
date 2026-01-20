/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:32:55 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 16:42:45 by spacotto         ###   ########.fr       */
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

void	build_stack(t_stacks *stacks, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{   
  		get_tokens(stacks, av[i]);
		i++;
    }
}
