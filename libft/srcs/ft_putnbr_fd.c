/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:54:41 by spacotto          #+#    #+#             */
/*   Updated: 2025/10/23 13:18:33 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nba;

	nba = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nba = -n;
	}
	if (nba > 9)
	{
		ft_putnbr_fd(nba / 10, fd);
		ft_putnbr_fd(nba % 10, fd);
	}
	else
		ft_putchar_fd(nba + '0', fd);
}
