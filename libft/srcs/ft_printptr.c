/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:06:22 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:50:55 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printptr(t_format *sformat)
{
	size_t		p;
	size_t		len;
	char		*s;

	p = (size_t)va_arg(sformat->args, void *);
	ft_utoa_base_buffer(p, "0123456789abcdef", sformat->buffer);
	s = sformat->buffer;
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
		len = ft_strlen("(nil)");
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(s, 1);
		len = ft_strlen(s) + 2;
	}
	sformat->print_len += len;
}
