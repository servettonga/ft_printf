/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:50:20 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 21:12:16 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(void *ptr, int fd, unsigned int *count)
{
	uintptr_t	addr;
	char		buffer[20];
	size_t		i;

	addr = (uintptr_t)ptr;
	if (!addr)
	{
		ft_printf_s("(nil)", 1, count);
		return ;
	}
	i = sizeof(buffer);
	buffer[--i] = '\0';
	while (addr > 0)
	{
		buffer[--i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	buffer[--i] = 'x';
	buffer[--i] = '0';
	ft_printf_s(buffer + i, fd, count);
}
