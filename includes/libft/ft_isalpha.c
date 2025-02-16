/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:12:17 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:23 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d", isalpha(0));
// 	printf("%d", isalpha(97));
// 	printf("%d", isalpha(65));
// 	printf("%d", isalpha(90));
// 	printf("%d", isalpha(30));
// 	printf("%d", isalpha(-12));
// 	printf("%d", isalpha(64));
// 	printf("\n");
// 	printf("%d", ft_isalpha(0));
// 	printf("%d", ft_isalpha(97));
// 	printf("%d", ft_isalpha(65));
// 	printf("%d", ft_isalpha(90));
// 	printf("%d", ft_isalpha(30));
// 	printf("%d", ft_isalpha(-12));
// 	printf("%d", ft_isalpha(64));
// 	printf("\n");
// }
