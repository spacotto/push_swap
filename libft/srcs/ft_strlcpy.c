/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:07:34 by spacotto          #+#    #+#             */
/*   Updated: 2025/10/25 19:59:29 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	len = 0;
	if (size == 0)
		return (src_len);
	if (src_len < size)
		len = src_len;
	else
		len = size - 1;
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (src_len);
}
