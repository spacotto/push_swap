/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:57:46 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/30 23:51:35 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// ============================================================================
// INCLUDES
// ============================================================================

# include <stdarg.h>
# include "libft.h"

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct s_format
{
	va_list	args;
	size_t	print_len;
	char	buffer[64];
}	t_format;

// ============================================================================
// PROTOTYPES
// ============================================================================

int		ft_printf(const char *format, ...);

void	ft_typefield(const char **format, t_format *sformat);
void	ft_printchar(t_format *sformat);
void	ft_printstr(t_format *sformat);
void	ft_printptr(t_format *sformat);
void	ft_printnbr(t_format *sformat);
void	ft_printunb(t_format *sformat);
void	ft_printhex_lower(t_format *sformat);
void	ft_printhex_upper(t_format *sformat);

#endif
