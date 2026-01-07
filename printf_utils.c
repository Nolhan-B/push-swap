/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:46:37 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/07 14:48:19 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(unsigned int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	write(2, &a, 1);
	return (1);
}

static void	ft_putchar_bis(char c)
{
	write(2, &c, 1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
		len++;
	}
	if (n < 10)
	{
		ft_putchar_bis(n + '0');
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(2, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(2, s, i);
	return (i);
}