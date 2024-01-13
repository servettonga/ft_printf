/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:43 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/13 13:48:19 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(int n, int fd, size_t *count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_printf_c('-', fd, count);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_printf_i(num / 10, fd, count);
		ft_printf_i(num % 10, fd, count);
	}
	else
		ft_printf_c(num + '0', fd, count);
}

void	ft_printf_u(unsigned int n, int fd, size_t *count)
{
	if (n >= 10)
	{
		ft_printf_i(n / 10, fd, count);
		ft_printf_i(n % 10, fd, count);
	}
	else
		ft_printf_c(n + '0', fd, count);
}

void	ft_printf_x(unsigned int n, bool upper, int fd, size_t *count)
{
	const char	*hex;
	char		buffer[9];
	int			i;

	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	i = 7;
	while (n >= 16)
	{
		buffer[i--] = hex[n % 16];
		n /= 16;
	}
	buffer[i] = hex[n];
	buffer[8] = '\0';
	ft_printf_s(buffer + i, fd, count);
}
