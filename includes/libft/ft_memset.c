/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:25:15 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:53:40 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int main()
// {
// 	char str[] = "hippohippo";
// 	printf("%s \n", (unsigned char *)ft_memset(str, -12, 5));
// }
