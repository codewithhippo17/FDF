/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:13:13 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:28 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d", isascii(0));
// 	printf("%d", isascii(128));
// 	printf("%d", isascii(127));
// 	printf("%d", isascii(32));
// 	printf("%d", isascii(15));
// 	printf("%d", isascii(-12));
// 	printf("%d", isascii(64));

// 	printf("\n");

// 	printf("%d", ft_isascii(0));
// 	printf("%d", ft_isascii(128));
// 	printf("%d", ft_isascii(127));
// 	printf("%d", ft_isascii(32));
// 	printf("%d", ft_isascii(15));
// 	printf("%d", ft_isascii(-12));
// 	printf("%d", ft_isascii(64));

// 	printf("\n");
// }
