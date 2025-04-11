/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:33:20 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:16:10 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void fun(unsigned int i, char *s)
// {
// 	if(i % 2 == 0)
// 	{
// 		*s = *s - 32;
// 	}
// }
// #include <stdio.h>
// int main()
// {
//     char str[] = "hippo";
//     ft_striteri(str, fun);
// 	printf("%s\n", str);
// }
