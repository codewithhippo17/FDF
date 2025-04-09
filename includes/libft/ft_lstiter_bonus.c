/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:46:51 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:36:07 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void f(void *content)
// {
// 	char *str = content;
// 	int i = 0;
// 	while (str[i])
// 	{
// 		if (i % 2 == 0)
// 		{
// 			str[i] = str[i] - 32;
// 		}
// 		i++;
// 	}
// }

// #include <stdio.h>
// int main()
// {
// 	t_list **lst = malloc(sizeof(t_list *));
// 	t_list *new;

// 	char str[] = "hippo";
// 	*lst = ft_lstnew(str);
// 	char first1[] = "with";
// 	new = ft_lstnew(first1);
// 	ft_lstadd_front(lst, new);
// 	char first2[] = "code";
// 	new = ft_lstnew(first2);
// 	ft_lstadd_front(lst, new);
// 	char	back[] = "back";
// 	new = ft_lstnew(back);
// 	ft_lstadd_back(lst, new);

// 	t_list *curent = *lst;
// 	while (curent)
// 	{
// 		printf("%s \n", (char *)curent->content);
// 		curent = curent->next;
// 	}
// 	printf("\n\n   after iter   \n\n");
// 	curent = *lst;
// 	ft_lstiter(curent, f);
// 	while (curent)
// 	{
// 		printf("%s \n", (char *)curent->content);
// 		curent = curent->next;
// 	}
// }
