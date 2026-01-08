/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:02:57 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/10 17:45:18 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printstr(t_format *sformat)
{
	char	*s;
	size_t	len;

	s = va_arg(sformat->args, char *);
	if (!s)
	{
		len = ft_strlen("(null)");
		ft_putstr_fd("(null)", 1);
	}
	else
	{
		len = ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	sformat->print_len += len;
}
