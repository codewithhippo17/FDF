/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:35 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:02:22 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	long		nb;
	int			len;

	if (n < 0)
		nb = -(long)n;
	else
		nb = n;
	len = ft_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	itoa = malloc(len + 1);
	if (!itoa)
		return (NULL);
	itoa[len--] = '\0';
	if (n < 0)
		itoa[0] = '-';
	while (len >= 0 && itoa[len] != '-')
	{
		itoa[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoa);
}

// #include <stdio.h>

// int main()
// {
// 	char *itoa = ft_itoa(0);	
// 	printf("%s\n", itoa);
// 	free(itoa);
// }
