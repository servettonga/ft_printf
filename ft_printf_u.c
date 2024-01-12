/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:09 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 20:54:40 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(unsigned int n, int fd, unsigned int *count)
{
	if (n >= 10)
	{
		ft_printf_i(n / 10, fd, count);
		ft_printf_i(n % 10, fd, count);
	}
	else
		ft_printf_c(n + '0', fd, count);
}
