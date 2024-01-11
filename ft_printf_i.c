#include "ft_printf.h"

int	ft_printf_i(int n, int fd)
{
	unsigned int	count;
	long			num;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_printf_c('-', fd);
		num *= -1;
	}
	if (num >= 10)
	{
		count += ft_printf_i(num / 10, fd);
		count += ft_printf_i(num % 10, fd);
	}
	else
		count += ft_printf_c(num + '0', fd);
	return (count);
}
