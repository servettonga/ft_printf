/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:48 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 20:58:04 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
		The ft_printf() function formats and prints a series of characters and
		values to the standard output stream stdout. Format specifications,
		beginning with a percent sign (%), determine the output format for any
		argument-list following the format-string. The format-string is a
		multibyte character string beginning and ending in its initial shift
		state.

	PARAMETERS
		C string that contains the text to be written to stdout.
		It can optionally contain embedded format specifiers that are replaced
		by the values specified in subsequent additional arguments and formatted
		as requested.

		A format specifier follows this prototype: [see compatibility note below]
		%[flags][width][.precision][length]specifier

		specifier	Output
		c			Character
		s			String of characters
		p			Pointer address
		d or i		Signed decimal integer
		u			Unsigned decimal integer
		x			Unsigned hexadecimal integer
		X			Unsigned hexadecimal integer (uppercase)
		f			Decimal floating point, lowercase
		e			Scientific notation (mantissa/exponent), lowercase
		g			Use the shortest representation: %e or %f
		n			Nothing printed.
					The corresponding argument must be a pointer to a signed int
		%			A % followed by another % character will write a single
					% to the stream.

		The format specifier can also contain sub-specifiers: flags, width,
		.precision and modifiers (in that order), which are optional and follow
		these specifications:

		flags		description
		-			Left-justify within the given field width; Right justification
					is the default (see width sub-specifier).
		+			Forces to preceed the result with a plus or minus sign (+ or
					-) even for positive numbers. By default, only negative
					numbers are preceded with a - sign.
		#			Used with o, x or X specifiers the value is preceeded
					with 0,
					0x or 0X respectively for values different than zero.
		0			Left-pads the number with zeroes (0) instead of spaces when
					padding is specified (see width sub-specifier).

		.precision	description
		.*			The precision is not specified in the format string, but as
					an additional integer value argument preceding the argument
					that has to be formatted.

		width		description
		(number)	Minimum number of characters to be printed. If the value to be
					printed is shorter than this number, the result is padded
					with blank spaces. The value is not truncated even if the
					result is larger.

		The length sub-specifier modifies the length of the data type.
					specifiers
		length		d i				u o x
		hh			signed char		unsigned char
		h			short int		unsigned short int
		l			long int		unsigned long int
		ll			long long int	unsigned long long int

	RETURN VALUE
		Upon successful return, this function returns the number of characters
		printed (excluding the null byte used to end output to strings).
*/

#include "ft_printf.h"

static void	ft_printf_args(const char *format, va_list args,
		unsigned int *count)
{
	if (*format == 'c')
		ft_printf_c(va_arg(args, int), 1, count);
	else if (*format == 's')
		ft_printf_s(va_arg(args, const char *), 1, count);
	else if (*format == 'p')
		ft_printf_p(va_arg(args, void *), 1, count);
	else if (*format == 'd' || *format == 'i')
		ft_printf_i(va_arg(args, int), 1, count);
	else if (*format == 'u')
		ft_printf_u(va_arg(args, int), 1, count);
}

static int	ft_vprintf(const char *format, va_list args)
{
	unsigned int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
			ft_printf_args(++format, args, &printed);
		else
			ft_printf_c(*format, 1, &printed);
		format++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	count = ft_vprintf(format, args);
	va_end(args);
	return (count);
}
