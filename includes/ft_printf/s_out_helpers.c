/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_out_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:50 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/15 21:18:59 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	out_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	out_s(va_list args)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		count = ft_putstr("(null)");
		return (count);
	}
	return (ft_putstr(s));
}

int	out_p(va_list args)
{
	void	*p;
	int		count;

	count = 0;
	p = va_arg(args, void *);
	if (!p)
	{
		count = ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_puthex((intptr_t)p, "0123456789abcdef");
	return (count);
}

int	out_x(va_list args)
{
	unsigned int	n;

	n = va_arg(args, int);
	return (ft_puthex(n, "0123456789abcdef"));
}

int	out_upx(va_list args)
{
	unsigned int	n;

	n = va_arg(args, int);
	return (ft_puthex(n, "0123456789ABCDEF"));
}
