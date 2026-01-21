/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:35:43 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/21 18:40:34 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *node)
{
	t_list	*node_copy;
	char	*content_copy;

	if (!node)
		return (NULL);
	content_copy = ft_strdup(node->content);
	if (!content_copy)
		return (NULL);
	node_copy = ft_lstnew(content_copy);
	if (!node_copy)
	{
		free(content_copy);
		return (NULL);
	}
	if (index)
		node_copy->index = node->index;
	return (node_copy);
}
