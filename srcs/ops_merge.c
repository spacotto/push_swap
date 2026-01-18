/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 17:24:03 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_rr(t_list  *cmp1, t_list  *cmp2)
{
	if ((ft_strcmp(cmp1->content, "ra\n") == 0 && 
		ft_strcmp(cmp2->content, "rb\n") == 0) ||
		(ft_strcmp(cmp1->content, "rb\n") == 0 &&
		ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			cmp1->content = "rr\n";
			free(cmp2->content);
			return (1);
		}
	else
		return (0);
}

int	merge_rrr(t_list  *cmp1, t_list  *cmp2)
{
	if ((ft_strcmp(cmp1->content, "rra\n") == 0 && 
		ft_strcmp(cmp2->content, "rrb\n") == 0) ||
		(ft_strcmp(cmp1->content, "rrb\n") == 0 &&
		ft_strcmp(cmp2->content, "rra\n") == 0))
		{
			cmp1->content = "rrr\n";
			free(cmp2->content);
			return (1);
		}
	else
		return (0);
}

int	rm_ra_rra(t_list  *cmp1, t_list  *cmp2)
{
	if ((ft_strcmp(cmp1->content, "ra\n") == 0 &&
		ft_strcmp(cmp2->content, "rra\n") == 0) ||
		(ft_strcmp(cmp1->content, "rra\n") == 0 && 
		ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			free(cmp1->content);
			free(cmp2->content);
			return (1);
		}
	else
		return (0);
}

int	rm_rb_rrb(t_list  *cmp1, t_list  *cmp2)
{
	if ((ft_strcmp(cmp1->content, "ra\n") == 0 &&
		ft_strcmp(cmp2->content, "rra\n") == 0) ||
		(ft_strcmp(cmp1->content, "rra\n") == 0 && 
		ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			free(cmp1->content);
			free(cmp2->content);
			return (1);
		}
	else
		return (0);
}

