/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stderr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:07:47 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/07 15:16:22 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putfloat(double n, int precision)
{
	int		len;
	long	int_part;
	double	dec_part;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	int_part = (long)n;
	len += ft_putnbr(int_part);
	if (precision > 0)
	{
		len += ft_putchar('.');
		dec_part = n - int_part;
		while (precision--)
		{
			dec_part *= 10;
			int_part = (long)dec_part;
			len += ft_putchar(int_part + '0');
			dec_part -= int_part;
		}
	}
	return (len);
}

static int	ft_write_to_percent(const char **str)
{
	int	len;

	len = 0;
	while (**str && **str != '%')
	{
		len += ft_putchar((unsigned int)**str);
		(*str)++;
	}
	return (len);
}

static int	ft_types(va_list *args, char c)
{
	int		len;

	len = 0;
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'c')
		len += ft_putchar(va_arg(*args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'f')
		len += ft_putfloat(va_arg(*args, double), 2);
	return (len);
}

int	ft_printf_stderr(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		len += ft_write_to_percent(&str);
		if (*str == '%')
		{
			str++;
			len += ft_types(&args, *str);
			str++;
		}
	}
	va_end(args);
	return (len);
}
