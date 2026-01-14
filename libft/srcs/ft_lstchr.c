/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:27:39 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 16:02:55 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstchr(t_list *haystack, t_list *needle)
{
	t_list	*current;
	int		position;

	position = 0;
	current = haystack;
	while (current != needle)
	{
		position++;
		current = current->next;
	}
	return (position);
}
