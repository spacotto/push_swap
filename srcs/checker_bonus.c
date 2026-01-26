/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:54:18 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 16:16:23 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_ops(char *token)
{
	if (ft_strcmp(token, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(token, "sb\n") == 0)
		return (2);
	else if (ft_strcmp(token, "ss\n") == 0)
		return (3);
	else if (ft_strcmp(token, "pa\n") == 0)
		return (4);
	else if (ft_strcmp(token, "pb\n") == 0)
		return (5);
	else if (ft_strcmp(token, "ra\n") == 0)
		return (6);
	else if (ft_strcmp(token, "rb\n") == 0)
		return (7);
	else if (ft_strcmp(token, "rr\n") == 0)
		return (8);
	else if (ft_strcmp(token, "rra\n") == 0)
		return (9);
	else if (ft_strcmp(token, "rrb\n") == 0)
		return (10);
	else if (ft_strcmp(token, "rrr\n") == 0)
		return (11);
	return (0);
}

static void	add_op(t_list **ops, char *token)
{
	size_t	len;
	char	*content;
	t_list	*new_node;

	len = ft_strlen(token);
	content = ft_calloc(len, sizeof(char));
	if (!content)
		return ;
	*content = *token;
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return ;
	}
	ft_lstadd_back(ops, new_node);
}

static void	make_ops(t_list **ops)
{
	char	*token;

	token = NULL;
	while (1)
	{
		token = get_next_line(0);
		if (!token)
			return ;
		if (check_ops(token) == 0)
		{
			error_msg();
			if (ops != NULL)
				ft_lstclear(ops, del);
			return ;
		}	
		else
			add_op(ops, token);
		free(token);
    }
}

static void	execute_op(t_stacks *stacks, char *op)
{
	if (check_ops(op) == 1)
		ft_sa_bonus(stacks);
	else if (check_ops(op) == 2)
		ft_sb_bonus(stacks);
	else if (check_ops(op) == 3)
		ft_ss_bonus(stacks);
	else if (check_ops(op) == 4)
		ft_pa_bonus(stacks);
	else if (check_ops(op) == 5)
		ft_pa_bonus(stacks);
	else if (check_ops(op) == 6)
		ft_ra_bonus(stacks);
	else if (check_ops(op) == 7)
		ft_rb_bonus(stacks);
	else if (check_ops(op) == 8)
		ft_rr_bonus(stacks);
	else if (check_ops(op) == 9)
		ft_rra_bonus(stacks);
	else if (check_ops(op) == 10)
		ft_rrb_bonus(stacks);
	else if (check_ops(op) == 11)
		ft_rrr_bonus(stacks);
}

int	checker(t_stacks *stacks, int ac, char **av)
{
	t_list	*current;

	make_stack(&stacks->stack_a, ac, av);
	if (!stacks->stack_a)
		return (0);
	make_ops(&stacks->operations);
	if (stacks->operations)
	{
		current = stacks->operations;
		while (current)
		{
			execute_op(stacks, current->content);
			current = current->next;
		}
		if (ft_lstsort_check(stacks->stack_a) == 1)
			ft_putstr_fd(BOLD_CYAN "OK\n" RESET, 1);
		else			
			ft_putstr_fd(BOLD_MAGENTA "KO\n" RESET, 1);
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
				ft_lstclear(&stacks.operations, del);
		}
		else
			return (-1);
	}
	return (0);
}
