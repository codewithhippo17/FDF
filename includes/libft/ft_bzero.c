/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:09:51 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:17:37 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (s == NULL)
		return ;
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	char str[] = "hippo hippo";
// 	ft_bzero(str, 5);
// 	while (i < 12)
// 	{
// 		if (str[i] == 0)
// 		{
// 			printf(" 0 ");
// 		}
// 		else
// 			printf("%c", str[i]);
// 		i++;
// 	}
// }
