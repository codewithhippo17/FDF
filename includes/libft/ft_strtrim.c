/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:40:26 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:26:32 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	is_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*trimed;
	int		i;
	int		last;
	int		first;

	i = 0;
	first = 0;
	last = ft_strlen(s1) - 1;
	trimed = malloc(ft_strlen(s1) + 1);
	if (!trimed)
		return (NULL);
	while (s1[first] && is_set(set, s1[first]) == 1)
		first++;
	while (last > first && is_set(set, s1[last]) == 1)
	{
		last--;
	}
	while (first < last + 1)
	{
		trimed[i] = s1[first];
		i++;
		first++;
	}
	trimed[i] = 0;
	return (trimed);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[] = "!!**hello!!**";
// 	char set[] = "!*";
// 	printf("%s\n", ft_strtrim(s1, set));
// }
