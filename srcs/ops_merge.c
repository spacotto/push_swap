/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/18 23:02:59 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_rr(t_list  *ops)
{
	t_list	*cmp1;
	t_list	*cmp2;

	if (!ops || !ops->next)
		return ;
	cmp1 = ops;
	while (cmp1 && cmp1->next)
	{
		cmp2 = cmp1->next;
		if ((ft_strcmp(cmp1->content, "ra\n") == 0 && 
			ft_strcmp(cmp2->content, "rb\n") == 0) ||
			(ft_strcmp(cmp1->content, "rb\n") == 0 &&
			ft_strcmp(cmp2->content, "ra\n") == 0))
		{
			free(cmp1->content);
			cmp1->content = ft_strdup("rr\n");
			cmp1->next = cmp2->next;
			ft_lstdelone(cmp2, del);
		}
		else
			cmp1 = cmp1->next;
	}
}

void	merge_rrr(t_list  *ops)
{
	t_list	*cmp1;
	t_list	*cmp2;

	if (!ops || !ops->next)
		return ;
	cmp1 = ops;
	while (cmp1 && cmp1->next)
	{
		cmp2 = cmp1->next;
		if ((ft_strcmp(cmp1->content, "rra\n") == 0 && 
			ft_strcmp(cmp2->content, "rrb\n") == 0) ||
			(ft_strcmp(cmp1->content, "rrb\n") == 0 &&
			ft_strcmp(cmp2->content, "rra\n") == 0))
		{
			free(cmp1->content);
			cmp1->content = ft_strdup("rrr\n");
			cmp1->next = cmp2->next;
			ft_lstdelone(cmp2, del);
		}
		else
			cmp1 = cmp1->next;
	}
}
