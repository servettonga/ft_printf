/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:48:16 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/19 14:49:06 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(unsigned char c, size_t *count, t_flags *flags)
{
	if (c == '\n')
		return ;
	flags->space_l = (flags->width - 1) * !flags->minus;
	flags->space_r = (flags->width - 1) * flags->minus;
	*count += 1 + flags->space_l * (flags->space_l > 0) + flags->space_r
		* (flags->space_r > 0);
	while (flags->space_l-- > 0)
		write(flags->fd, " ", 1);
	write(flags->fd, &c, 1);
	while (flags->space_r-- > 0)
		write(flags->fd, " ", 1);
}

void	_print_null(const char *str, t_flags *flags, size_t *count)
{
	size_t	len;

	len = ft_strlen(str);
	write(flags->fd, str, len);
	*count += len;
}

static void	_ft_print_buffer(const char *str, int len, t_flags *flags,
		size_t *count)
{
	char	*buffer;
	size_t	total_size;
	int		i;

	i = 0;
	total_size = flags->total_space + len + flags->plus;
	buffer = ft_calloc(sizeof(char), total_size + 3);
	if (buffer == NULL)
		return (_print_null("(null)", flags, count));
	if (flags->plus || flags->sign == '-')
		buffer[i++] = flags->sign;
	if (!flags->minus)
		while (flags->total_space-- > 0)
			buffer[i++] = flags->spacer;
	while (*str && len-- > 0)
		buffer[i++] = *str++;
	while (flags->total_space-- > 0)
		buffer[i++] = flags->spacer;
	write(flags->fd, buffer, i);
	*count += i;
	free(buffer);
}

void	_pre_buffer(const char *str, size_t *count, t_flags *flags)
{
	int	len;

	if (str == NULL)
		return (_print_null("(null)", flags, count));
	len = ft_strlen(str);
	if (len == 0 && (flags->width == 0 && flags->precision == 0))
		return ;
	if (flags->width > len)
		flags->total_space = flags->width - len;
	else if (flags->precision > len)
		flags->total_space = flags->precision - len + (flags->plus
				|| flags->sign == '-');
	flags->total_space += flags->space * (len >= 0) - (flags->plus
			|| flags->sign == '-');
	if (flags->zero || flags->precision > 0)
		flags->spacer = '0';
	_ft_print_buffer(str, len, flags, count);
}

void	ft_printf_s(const char *str, size_t *count, t_flags *flags)
{
	int	len;

	if (str == NULL)
		return (_print_null("(null)", flags, count));
	len = ft_strlen(str);
	if (flags->dot && flags->precision == 0)
		return ;
	if (len == 0 && (flags->width == 0))
		return ;
	if (flags->width > len)
		flags->total_space = flags->width - len;
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	_ft_print_buffer(str, len, flags, count);
}
