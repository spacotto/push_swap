/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:07:08 by spacotto          #+#    #+#             */
/*   Updated: 2025/10/27 22:51:53 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	d = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (*s)
		ft_memcpy(d, s, ft_strlen(s) + 1);
	return (d);
}
