/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:46:26 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/11 11:55:33 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	get_stack(char *s)
{
	t_stack	stack_a;
	char	*token;

	token = ft_strtok(s, " ");
	node = ft_atoi(token);
	while (token != NULL)
	{
		token = ft_strtok(NULL, " ");
		node = ft_atoi(token);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 1)
	{
		while (i <= ac)
		{
			i++;
			stack_a = get_stack(av[i]);
		}
		push_swap(stack_a);
	}
	return (0);
}
