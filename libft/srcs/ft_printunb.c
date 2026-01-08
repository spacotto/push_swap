/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:54:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:55:40 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printunb(t_format *sformat)
{
	size_t		u;
	size_t		len;
	char		*s;

	u = (size_t)va_arg(sformat->args, unsigned int);
	ft_utoa_base_buffer(u, "0123456789", sformat->buffer);
	s = sformat->buffer;
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	sformat->print_len += len;
}
