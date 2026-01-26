/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:48:53 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 16:37:50 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	index_init(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

static t_list	*find_smallest_unindexed(t_list *lst)
{
	t_list	*target;
	t_list	*current;

	target = NULL;
	current = lst;
	while (current)
	{
		if (current->index == -1)
		{
			if (!target
				|| *(int *)(current->content) < *(int *)(target->content))
				target = current;
		}
		current = current->next;
	}
	return (target);
}

void	ft_lstadd_index(t_list *lst)
{
	int		i;
	t_list	*smallest;

	i = 0;
	index_init(lst);
	while (i < ft_lstsize(lst))
	{
		smallest = find_smallest_unindexed(lst);
		smallest->index = i;
		i++;
	}
}
