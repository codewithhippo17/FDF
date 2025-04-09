/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:14:21 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:53 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d ", isprint(0));
// 	printf("%d ", isprint(97));
// 	printf("%d ", isprint(65));
// 	printf("%d ", isprint(90));
// 	printf("%d ", isprint(30));
// 	printf("%d ", isprint(128));
// 	printf("%d ", isprint(127));
// 	printf("\n");
// 	printf("%d ", ft_isprint(0));
// 	printf("%d ", ft_isprint(97));
// 	printf("%d ", ft_isprint(65));
// 	printf("%d ", ft_isprint(90));
// 	printf("%d ", ft_isprint(30));
// 	printf("%d ", ft_isprint(128));
// 	printf("%d ", ft_isprint(127));
// 	printf("\n");
// }
