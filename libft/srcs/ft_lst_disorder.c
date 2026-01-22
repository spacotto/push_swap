/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:48:02 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/22 18:00:07 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The disorder is a number between 0 and 1 stating how far your list is from
// being sorted. 0 represents a sorted list. 1 indicates that the values are 
// in the worst possible order. 
//
// Calculate the disorder: each time a bigger number appears before a smaller 
// one, that pair counts as a mistake. More mistakes = highest disorder.

double	ft_lst_disorder(t_list *lst)
{
	t_list	*current;
	t_list	*compare;
	int		mistakes;
	int		total_pairs;
	int		current_val;
	int		compare_val;

	mistakes = 0;
	total_pairs = 0;
	current = lst;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			current_val = *(int *)current->content;
			compare_val = *(int *)compare->content;
			if (current_val > compare_val)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
