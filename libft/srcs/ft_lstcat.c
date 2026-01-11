/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:42:52 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/11 18:47:34 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcat(t_list **lst1, t_list *lst2)
{
	t_list	*last;

	if (!lst1)
		return ;
	if (!*lst1)
	{
		*lst1 = lst2;
		return ;
	}
	last = ft_lstlast(*lst1);
	last->next = lst2;
}
