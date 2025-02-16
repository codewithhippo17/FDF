/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:41:41 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/16 15:39:03 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_if(va_list args, char c)
{
	if (c == 'c')
		return (out_c(args));
	else if (c == 'd' || c == 'i')
		return (out_d(args));
	else if (c == 'u')
		return (out_u(args));
	else if (c == 's')
		return (out_s(args));
	else if (c == 'x')
		return (out_x(args));
	else if (c == 'X')
		return (out_upx(args));
	else if (c == 'p')
		return (out_p(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += write(1, &format[i], 1);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += write(1, "%%", 1);
			i++;
		}
		else if (format[i] == '%' && ft_isset(format[i + 1]))
			count += print_if(args, format[++i]);
		else
			return (va_end(args), -1);
		i++;
	}
	va_end(args);
	return (count);
}
