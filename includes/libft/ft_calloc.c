/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:53 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:51:48 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, nmemb * size);
	return (res);
}

// #include <stdio.h>

// int main()
// {
// 	char *str;

// 	str = ft_calloc(5, 1);
// 	if (str)
// 		printf("allocation does not fail\n");
// 	int i = 0;
// 	while ( i < 5)
// 	{
// 		printf("%d ", str[i++]);
// 	}
// 	printf("\n");
// }