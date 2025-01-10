/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:19:36 by sehosaf           #+#    #+#             */
/*   Updated: 2025/01/10 13:41:02 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	__printf_specifier(const char *format, va_list args, size_t *count,
		t_flags *flags)
{
	if (*format == 'c')
		ft_printf_c(va_arg(args, int), count, flags);
	else if (*format == 's')
		ft_printf_s(va_arg(args, const char *), count, flags);
	else if (*format == 'p')
		ft_printf_p(va_arg(args, void *), count, flags);
	else if (*format == 'd' || *format == 'i')
		ft_printf_i(va_arg(args, int), count, flags);
	else if (*format == 'u')
		ft_printf_u(va_arg(args, int), count, flags);
	else if (*format == 'x' || *format == 'X')
		ft_printf_x(va_arg(args, unsigned int), *format == 'X', count, flags);
	else if (*format == '%')
		ft_printf_c('%', count, flags);
}

int	parse_format(const char *format, va_list args)
{
	t_flags	flags;
	size_t	count;

	count = 0;
	while (*format)
	{
		ft_init_flags(&flags);
		if (*format == '%')
		{
			format++;
			ft_set_flags(&flags, &format);
			if (ft_is_specifier(*format))
				__printf_specifier(format, args, &count, &flags);
		}
		else
			ft_printf_c(*format, &count, &flags);
		format++;
	}
	return (count);
}
