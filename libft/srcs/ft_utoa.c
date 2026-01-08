/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:45:46 by spacotto          #+#    #+#             */
/*   Updated: 2025/12/16 18:30:05 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(size_t n)
{
	t_itoa	t;

	t.base_len = ft_strlen("0123456789");
	t.len = ft_countdigits(n, t.base_len);
	t.result = ft_calloc(t.len + 1, sizeof(char));
	if (!t.result)
		return (NULL);
	while (t.len > 0)
	{
		t.len--;
		t.result[t.len] = (n % 10) + '0';
		n /= 10;
	}
	return (t.result);
}
