/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:04 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/11 22:55:28 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_sc
{
	size_t	len;
	size_t	width;
}			s_sc;

int			ft_printf(const char *format, ...);
int			ft_printf_c(unsigned char c, int fd);
int			ft_printf_s(const char *str, int fd);
int			ft_printf_i(int n, int fd);

#endif
