/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:48:16 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/13 13:48:43 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(unsigned char c, int fd, size_t *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_printf_s(const char *str, int fd, size_t *count)
{
	if (!str)
	{
		write(fd, "(null)", 6);
		*count += 6;
	}
	else
		while (*str)
			ft_printf_c(*str++, fd, count);
}
