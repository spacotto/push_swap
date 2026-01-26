/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:40:15 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/25 20:45:51 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsort_check(t_list *lst)
{
	t_list	*current;
	int		current_value;
	int		next_value;

	if (!lst || !lst->next)
		return (1);
	if (ft_lstsize(lst) == 1)
		return (1);
	current = lst;
	while (current->next)
	{
		current_value = *(int *)current->content;
		next_value = *(int *)current->next->content;
		if (current_value > next_value)
			return (0);
		current = current->next;
	}
	return (1);
}
