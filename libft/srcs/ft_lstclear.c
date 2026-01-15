/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:38:57 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 12:39:00 by spacotto         ###   ########.fr       */
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
