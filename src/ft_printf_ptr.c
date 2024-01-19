/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:50:20 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/19 18:12:37 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	__ptr_len(uintptr_t num)
{
	size_t	digits;

	digits = 0;
	while (num)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

void	ft_printf_p(void *ptr, size_t *count, t_flags *flags)
{
	uintptr_t	addr;
	char		*buffer;
	size_t		len;

	addr = (uintptr_t)ptr;
	if (!addr)
		return (_print_null("(nil)", count));
	len = __ptr_len(addr);
	buffer = ft_calloc(len + 3, sizeof(char));
	buffer[len + 2] = '\0';
	while (addr > 0)
	{
		buffer[--len + 2] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	buffer[1] = 'x';
	buffer[0] = '0';
	flags->sign = '\0';
	_pre_buffer(buffer, count, flags);
	free(buffer);
}
