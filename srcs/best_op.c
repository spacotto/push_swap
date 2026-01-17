/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/17 21:34:43 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_rr(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->content, "ra\n") == 0
			&& ft_strcmp(next->content, "rb\n") == 0)
		{
			current->content = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->content, "rb\n") == 0
			&& ft_strcmp(next->content, "ra\n") == 0)
		{
			current->content = "rr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}

void	merge_rrr(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (ft_strcmp(current->content, "rra\n") == 0
			&& ft_strcmp(next->content, "rrb\n") == 0)
		{
			current->content = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		if (ft_strcmp(current->content, "rrb\n") == 0
			&& ft_strcmp(next->content, "rra\n") == 0)
		{
			current->content = "rrr\n";
			current->next = next->next;
			free(next);
			continue;
		}
		current = current->next;
	}
}

void	rm_ra_rra(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;
	t_list	*tmp;
	
	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if ((ft_strcmp(current->content, "ra\n") == 0 &&
			ft_strcmp(next->content, "rra\n") == 0) ||
			(ft_strcmp(current->content, "rra\n") == 0 && 
			ft_strcmp(next->content, "ra\n") == 0))
		{
			current->next = next->next;
			free(next);
			tmp = current;
			current = stacks->operations;
			if (current == tmp)
				current = current->next;
			continue;
		}
		current = current->next;
	}
}

void	rm_rb_rrb(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;
	t_list	*tmp;

	current = stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if ((ft_strcmp(current->content, "rb\n") == 0 &&
			ft_strcmp(next->content, "rrb\n") == 0) ||
			(ft_strcmp(current->content, "rrb\n") == 0 && 
			ft_strcmp(next->content, "rb\n") == 0))
		{
			current->next = next->next;
			free(next);
			tmp = current;
			current = stacks->operations;
			if (current == tmp)
				current = current->next;
			continue;
		}
		current = current->next;
	}
}

