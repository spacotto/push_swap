/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:36:21 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:54:56 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printnbr(t_format *sformat)
{
	ssize_t		i;
	size_t		len;
	char		*s;

	i = (ssize_t)va_arg(sformat->args, int);
	ft_itoa_base_buffer(i, "0123456789", sformat->buffer);
	s = sformat->buffer;
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	sformat->print_len += len;
}
