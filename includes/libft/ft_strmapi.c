/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:36:32 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:21:26 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

// char f(unsigned int i, char c)
// {
// 	char s;
// 	s = c;
// 	if(i % 2 == 0)
// 	{
// 		s = c - 32;
// 	}
// 	return (s);
// }

// #include <stdio.h>
// int main()
// {
// 	char *mapi = ft_strmapi("hippo", f);
// 	printf("%s\n", mapi);
// }
