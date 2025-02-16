/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:20:11 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:53:11 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((const char *)s))
		return (ft_strdup(""));
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (s[start] && len != 0)
	{
		ret[i] = s[start];
		i++;
		start++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}

// #include <stdio.h>

// int main()
// {
//     char str[] = "hippo";
//     printf("%s\n", ft_substr(str, 10, 4));
//     return 0;
// }
