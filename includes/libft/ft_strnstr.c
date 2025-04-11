/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:39:27 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/12 21:31:36 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	if (len < len_little)
		return (NULL);
	while (*big && i + len_little <= len)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char big[] = "1,0xfff00f";
// 	char *little = ",0x";
// 	printf("%s \n", ft_strnstr(big, little, 16));
// }
