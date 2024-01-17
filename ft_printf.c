/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:48 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/17 14:29:48 by sehosaf          ###   ########.fr       */
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
		%			A % followed by another % character will write a single
					% to the stream.

		The format specifier can also contain sub-specifiers: flags, width,
		.precision and modifiers (in that order), which are optional and follow
		these specifications:

		flags		description
		-			Left-justify the result within the field width.
		+			Prefix the output value with a sign (+ or -) if the output
					value is of a signed type.
		(space)		If no sign is going to be written, a blank space is inserted
					before the value.
		#			Used with o, x or X specifiers the value is preceeded
					with 0,
					0x or 0X respectively for values different than zero.
		0			Left-pads the number with zeroes (0) instead of spaces when
					padding is specified (see width sub-specifier).

		width		description
		(number)	Minimum number of characters to be printed. If the value
					to be printed is shorter than this number, the result is
					padded with blank spaces.
		*			The width is not specified in the format string, but as
					an additional integer value argument preceding the argument
					that has to be formatted.

	RETURN VALUE
		Upon successful return, this function returns the number of characters
		printed (excluding the null byte used to end output to strings).
*/

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	count = ft_printf_arg(format, args);
	va_end(args);
	return (count);
}
