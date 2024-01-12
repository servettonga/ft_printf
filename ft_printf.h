/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:04 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/12 20:49:13 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_sc
{
	size_t	len;
	size_t	width;
}			s_sc;

int			ft_printf(const char *format, ...);
void		ft_printf_c(unsigned char c, int fd, unsigned int *count);
void		ft_printf_s(const char *str, int fd, unsigned int *count);
void		ft_printf_i(int n, int fd, unsigned int *count);
void		ft_printf_p(void *ptr, int fd, unsigned int *count);
void		ft_printf_u(unsigned int n, int fd, unsigned int *count);

#endif
