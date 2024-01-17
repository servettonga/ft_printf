/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:48:16 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/17 14:17:27 by sehosaf          ###   ########.fr       */
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

static void	_print_null(t_flags *flags, size_t *count)
{
	write(flags->fd, "(null)", 6);
	*count += 6 + flags->width;
}

static void	_ft_print_buffer(const char *str, char spacer, t_flags *flags,
		size_t *count)
{
	char	*buffer;
	size_t	total_size;
	int		i;

	i = 0;
	total_size = flags->space_l + flags->space_r + ft_strlen(str) + flags->plus;
	buffer = ft_calloc(sizeof(char), total_size + 3);
	if (buffer == NULL)
		return (_print_null(flags, count));
	if (flags->plus || flags->sign == '-')
	{
		buffer[i++] = flags->sign;
		total_size++;
	}
	while (flags->space_l-- > 0)
		buffer[i++] = spacer;
	while (*str)
		buffer[i++] = *str++;
	while (flags->space_r-- > 0)
		buffer[i++] = spacer;
	write(flags->fd, buffer, i);
	*count += i;
	free(buffer);
}

void	ft_printf_s(const char *str, size_t *count, t_flags *flags)
{
	int		total_space;
	char	spacer;
	size_t	len;

	if (str == NULL)
		return (_print_null(flags, count));
	total_space = 0;
	len = ft_strlen(str);
	if (len == 0 && flags->width == 0)
		return ;
	if (flags->width > len)
		total_space = flags->width - len;
	total_space += flags->space * (len > 0) - (flags->plus
			|| flags->sign == '-');
	flags->space_l = total_space * !flags->minus;
	flags->space_r = total_space * flags->minus;
	spacer = ' ';
	if (flags->zero)
		spacer = '0';
	_ft_print_buffer(str, spacer, flags, count);
}
