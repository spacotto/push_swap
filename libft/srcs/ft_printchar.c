/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:00:57 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/07 16:39:29 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printchar(t_format *sformat)
{
	char	c;

	c = va_arg(sformat->args, int);
	ft_putchar_fd(c, 1);
	sformat->print_len++;
}
