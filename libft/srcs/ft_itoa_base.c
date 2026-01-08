/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:14:48 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/28 10:24:51 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(ssize_t n, char *base)
{
	t_itoa	t;

	t.base_len = ft_strlen(base);
	t.len = ft_countdigits(n, t.base_len);
	t.result = ft_calloc(t.len + 1, sizeof(char));
	if (!t.result)
		return (NULL);
	t.flag = 0;
	if (n < 0)
	{
		t.result[0] = '-';
		n = -n;
		t.flag = 1;
	}
	if (n == 0)
		t.result[0] = '0';
	while (t.len > t.flag)
	{
		t.len--;
		t.result[t.len] = base[n % t.base_len];
		n /= t.base_len;
	}
	return (t.result);
}
