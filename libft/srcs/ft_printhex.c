/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:19:19 by spacotto          #+#    #+#             */
/*   Updated: 2025/12/01 00:00:33 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printhex_lower(t_format *sformat)
{
	size_t		hex;
	char		*s;
	size_t		len;

	hex = (size_t)va_arg(sformat->args, unsigned int);
	ft_utoa_base_buffer(hex, "0123456789abcdef", sformat->buffer);
	s = sformat->buffer;
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	sformat->print_len += len;
}

void	ft_printhex_upper(t_format *sformat)
{
	size_t		hex;
	char		*s;
	size_t		len;

	hex = (size_t)va_arg(sformat->args, unsigned int);
	ft_utoa_base_buffer(hex, "0123456789ABCDEF", sformat->buffer);
	s = sformat->buffer;
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	sformat->print_len += len;
}
