/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:54:56 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/22 14:23:16 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ra_rra(char *op1, char *op2)
{
	if (!op1 || !op2)
		return (0);
	if (ft_strcmp(op1, "ra\n") == 0 && ft_strcmp(op2, "rra\n") == 0)
		return (1);
	if (ft_strcmp(op1, "rra\n") == 0 && ft_strcmp(op2, "ra\n") == 0)
		return (1);
	return (0);
}

static int	is_rb_rrb(char *op1, char *op2)
{
	if (!op1 || !op2)
		return (0);
	if (ft_strcmp(op1, "rb\n") == 0 && ft_strcmp(op2, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(op1, "rrb\n") == 0 && ft_strcmp(op2, "rb\n") == 0)
		return (1);
	return (0);
}

static int	is_pa_pb(char *op1, char *op2)
{
	if (!op1 || !op2)
		return (0);
	if (ft_strcmp(op1, "pa\n") == 0 && ft_strcmp(op2, "pb\n") == 0)
		return (1);
	if (ft_strcmp(op1, "pb\n") == 0 && ft_strcmp(op2, "pa\n") == 0)
		return (1);
	return (0);
}

int	redundancy(t_list *op1, t_list *op2)
{
	if (is_ra_rra(op1->content, op2->content))
		return (1);	
	if (is_rb_rrb(op1->content, op2->content))
		return (1);
	if (is_pa_pb(op1->content, op2->content))
		return (1);
	return (0);
}	
