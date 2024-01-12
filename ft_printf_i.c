/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:43 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 20:54:03 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(int n, int fd, unsigned int *count)
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
