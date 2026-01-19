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

static int	is_ra_rra(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, "ra\n") == 0 && ft_strcmp(s2, "rra\n") == 0)
		return (1);
	if (ft_strcmp(s1, "rra\n") == 0 && ft_strcmp(s2, "ra\n") == 0)
		return (1);
	return (0)
}

static int	is_rb_rrb(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, "rb\n") == 0 && ft_strcmp(s2, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(s1, "rrb\n") == 0 && ft_strcmp(s2, "rb\n") == 0)
		return (1);
	return (0);
}

static void	delete_redundant_pair(t_list **ops, t_list *prev, t_list *cmp1)
{
	t_list	*cmp2;

	cmp2 = cmp1->next;
	if (prev)
		prev->next = cmp2->next;
	else
		*ops = cmp2->next;
	ft_lstdelone(cmp1, del);
	ft_lstdelone(cmp2, del);
}

void	rm_redundancy(t_list **ops)
{
	t_list	*prev;
	t_list	*cmp1;

	if (!ops || !*ops || !(*ops)->next)
		return ;
	prev = NULL;
	cmp1 = *ops;
	while (cmp1 && cmp1->next)
	{
		if (is_ra_rra(cmp1->content, cmp1->next->content) ||
			is_rb_rrb(cmp1->content, cmp1->next->content))
		{
			delete_redundant_pair(ops, prev, cmp1);
			if (prev)
				cmp1 = prev->next;
			else
				cmp1 = *ops;
		}
		else
		{
			prev = cmp1;
			cmp1 = cmp1->next;
		}
	}
}
