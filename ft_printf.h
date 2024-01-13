/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:04 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/13 19:46:57 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_printf_c(unsigned char c, int fd, size_t *count);
void	ft_printf_s(const char *str, int fd, size_t *count);
void	ft_printf_i(int n, int fd, size_t *count);
void	ft_printf_p(void *ptr, int fd, size_t *count);
void	ft_printf_u(unsigned int n, int fd, size_t *count);
void	ft_printf_x(unsigned int n, bool upper, int fd, size_t *count);
void	ft_printf_f(double n, int fd, size_t *count);

#endif
