/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:54:18 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 00:03:10 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_msg()
{
	ft_putstr_fd(BOLD_RED "Error\n" RESET, 2);
}

static int	is_op(char *s)
{}

static void	get_ops(t_stacks *stacks)
{}

static void	choose_op(t_list *op)
{}

static void	execute_ops(t_stacks *stacks)
{}

int	checker(t_stacks *stacks, int ac, char **av)
{
	make_stack(stacks->stack_a, ac, av);
	get_ops(stacks);
	if (stacks->stack_a && stacks->ops)
	{
		execute_ops(stacks);
		if (ft_lstsort_check(stacks->stack_a) == 1)
			ft_putstr_fd(BOLD_GREEN "OK\n" RESET, );
		else			
			ft_putstr_fd(BOLD_RED "KO\n" RESET, );
		return (1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	ft_memset(&stacks, 0, sizeof(t_stacks));
	if (ac > 1)
	{
		if (checker(&stacks, ac, av) == 1)
		{
			if (stacks.stack_a != NULL)
				ft_lstclear(&stacks.stack_a, del);
			if (stacks.operations != NULL)
				ft_lstclear(&stacks.ops, del);
			return (0);
		}
		else
			return (-1);
	}
	return (0);
}
