/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:11:34 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:10 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (8);
	if (c >= 48 && c <= 57)
		return (8);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d", isalnum(0));
// 	printf("%d", isalnum(97));
// 	printf("%d", isalnum(48));
// 	printf("%d", isalnum(90));
// 	printf("%d", isalnum(30));
// 	printf("%d", isalnum(-12));
// 	printf("%d", isalnum(57));
// 	printf("\n");
// 	printf("%d", ft_isalnum(0));
// 	printf("%d", ft_isalnum(97));
// 	printf("%d", ft_isalnum(48));
// 	printf("%d", ft_isalnum(90));
// 	printf("%d", ft_isalnum(30));
// 	printf("%d", ft_isalnum(-12));
// 	printf("%d", ft_isalnum(57));
// 	printf("\n");
// }