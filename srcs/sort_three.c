/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:49:21 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 14:49:27 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = *(int *)stacks->stack_a->content;
	n2 = *(int *)stacks->stack_a->next->content;
	n3 = *(int *)stacks->stack_a->next->next->content;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(stacks);
	else if (n1 > n2 && n2 > n3)
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_ra(stacks);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_rra(stacks);
}
