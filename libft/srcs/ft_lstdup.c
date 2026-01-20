/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:35:43 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/20 17:35:49 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;
	char	*new_content;

	if (!lst)
		return (NULL);
	new_list = NULL;
	current = lst;
	while (current)
	{
		new_content = ft_strdup(current->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, free);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			free(new_content);
			ft_lstclear(&new_list, free);
			return (NULL);
		}
		new_node->index = current->index;
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}
