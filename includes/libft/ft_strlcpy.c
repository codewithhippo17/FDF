/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:45:53 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:20:37 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[] = "hipppppppp";
// 	char dest[50];
// 	printf("%u\n", (int)ft_strlcpy(dest, str, 0));
// 	printf("%s\n", dest);

// 	char str1[] = "hipppppppp";
// 	char dest1[50];
// 	printf("%d\n", (int)strlcpy(dest1, str1, 0));
// 	printf("%s\n", dest1);
// }
