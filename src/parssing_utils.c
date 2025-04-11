/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 05:43:31 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/15 11:14:17 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *point)
{
	int	i;
	int	res;

	i = 3;
	res = 0;
	if (!point)
		return (0xFFFFFF);
	while (point[i] != '\n' && point[i])
	{
		if (point[i] >= '0' && point[i] <= '9')
			res = res * 16 + point[i] - 48;
		else if (point[i] >= 'a' && point[i] <= 'f')
			res = res * 16 + point[i] - 87;
		else if (point[i] >= 'A' && point[i] <= 'F')
			res = res * 16 + point[i] - 55;
		i++;
	}
	return (res);
}

int	is_dec(char *big, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if ((big[i] == '-' || big[i] == '+') && i == 0)
			i++;
		if (ft_isdigit(big[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_hex(char *big)
{
	int	i;

	i = 3;
	if (!big)
		return (0);
	if (ft_strlen(big) > 9)
		return (0);
	while (big[i])
	{
		if (ft_isdigit(big[i]))
			i++;
		else if (big[i] >= 'a' && big[i] <= 'f')
			i++;
		else if (big[i] >= 'A' && big[i] <= 'F')
			i++;
		else
			return (0);
	}
	return (1);
}

int	v_point(char *big)
{
	char	*little;

	if (!big || !*big)
		return (0);
	little = ft_strnstr(big, ",0x", ft_strlen(big));
	if (!little && is_dec(big, ft_strlen(big)))
	{
		return (1);
	}
	else if (is_dec(big, ft_strlenz(big)) && is_hex(little))
	{
		return (1);
	}
	return (0);
}
