/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:04:11 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/13 11:52:21 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_typefield(const char **format, t_format *sformat)
{
	if (**format == 'c')
		ft_printchar(sformat);
	else if (**format == 's')
		ft_printstr(sformat);
	else if (**format == 'p')
		ft_printptr(sformat);
	else if (**format == 'd' || **format == 'i')
		ft_printnbr(sformat);
	else if (**format == 'u')
		ft_printunb(sformat);
	else if (**format == 'x')
		ft_printhex_lower(sformat);
	else if (**format == 'X')
		ft_printhex_upper(sformat);
	else if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		sformat->print_len++;
	}
	else
	{
		ft_putchar_fd(**format, 1);
		sformat->print_len++;
	}
	(*format)++;
}

int	ft_printf(const char *format, ...)
{
	t_format	f;

	f.print_len = 0;
	va_start(f.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_bzero(f.buffer, 64);
			ft_typefield(&format, &f);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			f.print_len++;
			format++;
		}
	}
	va_end(f.args);
	return (f.print_len);
}
