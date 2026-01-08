/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:36:48 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:05:00 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(ssize_t n)
{
	t_itoa	t;

	t.base_len = ft_strlen("0123456789");
	t.len = ft_countdigits(n, t.base_len);
	t.result = ft_calloc(t.len + 1, sizeof(char));
	if (!t.result)
		return (NULL);
	if (n < 0)
	{
		t.result[0] = '-';
		n = -n;
	}
	if (n == 0)
		t.result[0] = '0';
	while (n > 0)
	{
		t.len--;
		t.result[t.len] = (n % 10) + '0';
		n /= 10;
	}
	return (t.result);
}
