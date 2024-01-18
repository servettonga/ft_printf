/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:43 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/18 23:31:09 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(int n, size_t *count, t_flags *flags)
{
	long	num;
	char	*buffer;
	int		i;

	num = n;
	buffer = ft_calloc(12, sizeof(char));
	if (num < 0)
	{
		flags->sign = '-';
		num *= -1;
	}
	i = 10;
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = (num % 10) + '0';
		num /= 10;
	}
	buffer[11] = '\0';
	_pre_buffer(buffer + i, count, flags);
	free(buffer);
}

void	ft_printf_u(unsigned int n, size_t *count, t_flags *flags)
{
	char	*buffer;
	int		i;

	buffer = ft_calloc(20, sizeof(char));
	i = 18;
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	buffer[19] = '\0';
	_pre_buffer(buffer + i, count, flags);
	free(buffer);
}

void	ft_printf_x(unsigned int n, bool upper, size_t *count, t_flags *flags)
{
	const char		*hex;
	char			buffer[16];
	int				i;
	unsigned int	init_n;

	init_n = n;
	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	i = 14;
	while (n >= 16)
	{
		buffer[i--] = hex[n % 16];
		n /= 16;
	}
	buffer[i--] = hex[n];
	if (flags->sharp && init_n != 0)
	{
		if (upper)
			buffer[i--] = 'X';
		else
			buffer[i--] = 'x';
		buffer[i--] = '0';
	}
	buffer[i] = '\0';
	buffer[15] = '\0';
	_pre_buffer(buffer + i + 1, count, flags);
}
