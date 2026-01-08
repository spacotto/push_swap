/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:54:19 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/07 16:38:04 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits_base(size_t n, size_t blen)
{
	size_t	counter;

	counter = 1;
	while (n >= blen)
	{
		n /= blen;
		counter++;
	}
	return (counter);
}

char	*ft_utoa_base(size_t n, char *base)
{
	size_t	blen;
	size_t	len;
	char	*s;

	blen = ft_strlen(base);
	len = countdigits_base(n, blen);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (len > 0)
	{
		len--;
		s[len] = base[n % blen];
		n /= blen;
	}
	return (s);
}
