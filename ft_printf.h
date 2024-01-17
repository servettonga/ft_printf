/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:04 by sehosaf           #+#    #+#             */
/*   Updated: 2024/01/17 13:55:20 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	bool	minus;
	bool	plus;
	bool	space;
	int		space_l;
	int		space_r;
	bool	sharp;
	bool	zero;
	bool	precision;
	size_t	width;
	char	sign;
	int		fd;
}			t_flags;

int			ft_printf(const char *format, ...);
int			ft_printf_arg(const char *format, va_list args);
void		ft_printf_c(unsigned char c, size_t *count, t_flags *flags);
void		ft_printf_s(const char *str, size_t *count, t_flags *flags);
void		ft_printf_i(int n, size_t *count, t_flags *flags);
void		ft_printf_p(void *ptr, size_t *count, t_flags *flags);
void		ft_printf_u(unsigned int n, size_t *count, t_flags *flags);
void		ft_printf_x(unsigned int n, bool upper, size_t *count,
				t_flags *flags);

// Flags
void		ft_init_flags(t_flags *flags);
void		ft_set_flags(t_flags *flags, const char **format);
bool		ft_is_flag(char format);
bool		ft_is_specifier(char format);

#endif
