/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:08:09 by spacotto          #+#    #+#             */
/*   Updated: 2025/10/27 17:50:46 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*node;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		node = head->next;
		ft_lstdelone(head, del);
		head = node;
	}
	*lst = NULL;
}
