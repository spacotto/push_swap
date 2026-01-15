/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:40:44 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/15 15:40:49 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *haystack, t_list *needle)
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
