/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 17:36:04 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isrr(char *op1, char *op2)
{
	if (ft_strcmp(op1, "ra\n") == 0 && ft_strcmp(op2, "rb\n") == 0)
		return (1);
	if (ft_strcmp(op1, "rb\n") == 0 && ft_strcmp(op2, "ra\n") == 0)
		return (1);
	return (0);
}

static void	merge_rr(t_list **target_list)
{
	t_list	*merged_node;
	char	*new_op;

	new_op = ft_strdup("rr\n");
	if (!new_op)
		return ;
	merged_node = ft_lstnew(new_op);
	if (!merged_node)
	{
		free(new_op);
		return ;
	}
	ft_lstadd_back(target_list, merged_node);
}

static int	isrrr(char *op1, char *op2)
{
	if (ft_strcmp(op1, "rra\n") == 0 && ft_strcmp(op2, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(op1, "rrb\n") == 0 && ft_strcmp(op2, "rra\n") == 0)
		return (1);
	return (0);
}

static void	merge_rrr(t_list **target_list)
{
	t_list	*merged_node;
	char	*new_op;

	new_op = ft_strdup("rrr\n");
	if (!new_op)
		return ;
	merged_node = ft_lstnew(new_op);
	if (!merged_node)
	{
		free(new_op);
		return ;
	}
	ft_lstadd_back(target_list, merged_node);
}

int	merge(t_list **target_list, char *op1, char *op2)
{
	if (isrr(op1, op2))
	{
		merge_rr(target_list);
		return (1);
	}
	else if (isrrr(op1, op2))
	{
		merge_rrr(target_list);
		return (1);
	}
	return (0);
}
