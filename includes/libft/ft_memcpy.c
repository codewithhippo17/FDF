/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:39:16 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:09:35 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[] = "code with hippo ";
// 	char dest[51];
//     printf("%s \n", (char *)ft_memcpy(dest, str1, 3));
//     return 0;
// }
