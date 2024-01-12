/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:48:16 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 20:51:23 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_s(const char *str, int fd, unsigned int *count)
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
