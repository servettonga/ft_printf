/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:58:37 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/19 18:05:46 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->minus = false;
	flags->plus = false;
	flags->space = false;
	flags->total_space = 0;
	flags->spacer = ' ';
	flags->zero = false;
	flags->sharp = false;
	flags->dot = false;
	flags->precision = 0;
	flags->width = 0;
	flags->sign = '+';
}

bool	ft_is_flag(char format)
{
	const char	*g_flags = "-+ 0#.";

	while (*g_flags)
		if (*g_flags++ == format || ft_isdigit(format))
			return (true);
	return (false);
}

bool	ft_is_specifier(char format)
{
	const char	*g_specifiers = "cspdiuxX%";

	while (*g_specifiers)
		if (*g_specifiers++ == format)
			return (true);
	return (false);
}

static void	__set_precision(t_flags *flags, const char **format)
{
	flags->dot = true;
	while (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		flags->precision = (flags->precision * 10) + **format - '0';
	}
}

void	ft_set_flags(t_flags *flags, const char **format)
{
	while (*format != NULL && ft_is_flag(**format))
	{
		if (**format == '-')
			flags->minus = true;
		else if (**format == ' ')
			flags->space = true;
		else if (**format == '+')
			flags->plus = true;
		else if (**format == '#')
			flags->sharp = true;
		else if (**format == '.')
			__set_precision(flags, format);
		else if (ft_isdigit(**format))
		{
			if (**format == '0' && flags->width == 0)
				flags->zero = true;
			flags->width = (flags->width * 10) + **format - '0';
		}
		(*format)++;
	}
}
