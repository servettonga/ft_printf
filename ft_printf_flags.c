/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:58:37 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/17 14:29:53 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->minus = false;
	flags->plus = false;
	flags->space = false;
	flags->space_l = 0;
	flags->space_r = 0;
	flags->zero = false;
	flags->sharp = false;
	flags->precision = 0;
	flags->width = 0;
	flags->sign = '+';
	flags->fd = 1;
}

bool	ft_is_flag(char format)
{
	const char	*g_flags = "-+ 0#.*";

	while (*g_flags)
		if (*g_flags++ == format || ft_isdigit(format))
			return (true);
	return (false);
}

bool	ft_is_specifier(char format)
{
	const char	*g_specifiers = "cspdiuxXf%";

	while (*g_specifiers)
		if (*g_specifiers++ == format)
			return (true);
	return (false);
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
		{
			flags->plus = true;
			flags->space = false;
		}
		else if (**format == '#')
			flags->sharp = true;
		else if (**format == '0' && !ft_isdigit(*(*format - 1)))
			flags->zero = true;
		if (ft_isdigit(**format))
		{
			if (**format == '0' && flags->width == 0)
				flags->zero = true;
			flags->width = (flags->width * 10) + **format - '0';
		}
		(*format)++;
	}
}
