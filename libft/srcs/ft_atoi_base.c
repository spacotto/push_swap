/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:35:10 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/06 18:27:50 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *nptr, int base)
{
	t_atoi	t;

	t.i = 0;
	t.sign = 1;
	t.result = 0;
	while (ft_isspace(nptr[t.i]) == 1)
		t.i++;
	if (nptr[t.i] == '+' || nptr[t.i] == '-')
	{
		if (nptr[t.i] == '-')
			t.sign = -1;
		t.i++;
	}
	while (nptr[t.i])
	{
		t.result *= base;
		if (nptr[t.i] >= '0' && nptr[t.i] <= '9')
			t.result += nptr[t.i] - '0';
		else if (nptr[t.i] >= 'a' && nptr[t.i] <= 'f')
			t.result += nptr[t.i] - 'a' + 10;
		else if (nptr[t.i] >= 'A' && nptr[t.i] <= 'F')
			t.result += nptr[t.i] - 'A' + 10;
		t.i++;
	}
	return (t.result * t.sign);
}
