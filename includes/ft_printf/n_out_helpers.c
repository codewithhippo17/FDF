/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_out_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:12:04 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/15 18:08:54 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	out_d(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}

int	out_u(va_list args)
{
	unsigned int	n;

	n = (unsigned int)va_arg(args, unsigned int);
	return (ft_putnbr_u(n));
}

int	out_i(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}
