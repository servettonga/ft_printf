/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:48:16 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/11 23:28:16 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(const char *str, int fd)
{
	unsigned	count;

	count = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*str)
		count += ft_printf_c(*str++, fd);
	return (count);
}
