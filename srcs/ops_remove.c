/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:54:56 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 23:06:09 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rm_ra_rra(t_list  *ops)
{
	if ((ft_strcmp(cmp1->content, "ra\n") == 0 &&
		ft_strcmp(cmp2->content, "rra\n") == 0) ||
		(ft_strcmp(cmp1->content, "rra\n") == 0 &&
		ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			free(cmp1->content);
			free(cmp2->content);
			return ;
		}
}

void	rm_rb_rrb(t_list  *ops)
{
	if ((ft_strcmp(cmp1->content, "ra\n") == 0 &&
		ft_strcmp(cmp2->content, "rra\n") == 0) ||
		(ft_strcmp(cmp1->content, "rra\n") == 0 &&
		ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			free(cmp1->content);
			free(cmp2->content);
			return ;
		}
}
