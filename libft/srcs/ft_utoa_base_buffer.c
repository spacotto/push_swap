/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:40:49 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:59:49 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_utoa_base_buffer(size_t n, char *base, char *buffer)
{
	t_itoa	t;

	t.base_len = ft_strlen(base);
	t.len = ft_countdigits(n, t.base_len);
	while (t.len > 0)
	{
		t.len--;
		buffer[t.len] = base[n % t.base_len];
		n /= t.base_len;
	}
}
