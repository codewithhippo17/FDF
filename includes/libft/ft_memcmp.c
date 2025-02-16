/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:22 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:07:32 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (i == n)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
// 	printf("  %d  ", ft_memcmp("happo", "hippo", 5));
// 	printf("  %d  ", ft_memcmp("hippo", "abcippo", 0));
// 	printf("  %d  ", ft_memcmp("hi ppo", "hip", 3));
// 	printf("  %d  ", ft_memcmp("hippo", "hippa", 5));
// 	printf("  %d  ", ft_memcmp("hippoabc", "hippobca", 5));
// 	printf("  %d  ", ft_memcmp("code with hippo", "code sith hippo", 5));
// 	printf("\n");
// 	printf("  %d  ", memcmp("happo", "hippo", 5));
// 	printf("  %d  ", memcmp("hippo", "abcippo", 0));
// 	printf("  %d  ", memcmp("hi ppo", "hip", 3));
// 	printf("  %d  ", memcmp("hippo", "hippa", 5));
// 	printf("  %d  ", memcmp("hippoabc", "hippobca", 5));
// 	printf("  %d  ", memcmp("code with hippo", "code sith hippo", 5));
// 	printf("\n");
// }
