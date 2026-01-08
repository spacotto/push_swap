/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:34:19 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/28 10:11:30 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigits(ssize_t n, ssize_t base_len)
{
	size_t	counter;

	counter = 1;
	if (n < 0)
	{
		counter++;
		n = -n;
	}
	while (n >= base_len)
	{
		n /= base_len;
		counter++;
	}
	return (counter);
}
