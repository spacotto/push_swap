/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:31:44 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/01 15:01:37 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_and_replace(char *s, char search, char replace)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == search)
			s[i] = replace;
		i++;
	}
	return (s);
}
