/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:14:07 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:58:40 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_base_buffer(ssize_t n, char *base, char *buffer)
{
	t_itoa	t;

	t.base_len = ft_strlen(base);
	t.len = ft_countdigits(n, t.base_len);
	t.flag = 0;
	if (n < 0)
	{
		buffer[0] = '-';
		n = -n;
		t.flag = 1;
	}
	if (n == 0)
		buffer[0] = '0';
	while (t.len > t.flag)
	{
		t.len--;
		buffer[t.len] = base[n % t.base_len];
		n /= t.base_len;
	}
}
