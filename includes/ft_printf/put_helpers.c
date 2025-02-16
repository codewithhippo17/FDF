/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:16:55 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/16 15:42:31 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_u(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_puthex(intptr_t n, char *base)
{
	char	str[16];
	char	rev[16];
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar(48));
	while (n)
	{
		str[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		rev[j] = str[i - 1];
		j++;
		i--;
	}
	rev[j] = '\0';
	return (ft_putstr(rev));
}
