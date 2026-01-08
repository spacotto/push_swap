/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:48:02 by spacotto          #+#    #+#             */
/*   Updated: 2025/10/20 14:24:47 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while (*big && len >= len_little)
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, len_little) == 0)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
