/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:39 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:40:29 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
	lst = NULL;
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

// void del(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>
// int main()
// {
// 	t_list **lst = malloc(sizeof(t_list *));
// 	t_list *new;

// 	*lst = ft_lstnew(ft_strdup("hippo"));

// 	new = ft_lstnew(ft_strdup("with"));
// 	ft_lstadd_front(lst, new);

// 	new = ft_lstnew(ft_strdup("code"));
// 	ft_lstadd_front(lst, new);

// 	new = ft_lstnew(ft_strdup("back"));
// 	ft_lstadd_back(lst, new);

// 	t_list *current = *lst;
// 	while (current)
// 	{
// 		printf("%s \n", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("\n\n   after iter   \n\n");
// 	current = *lst;
// 	ft_lstiter(current, f);
// 	current = *lst;
// 	while (current)
// 	{
// 		printf("%s \n", (char *)current->content);
// 		current = current->next;
// 	}
// 	current = *lst;
// 	t_list *pass = *lst;
// 	t_list *last = ft_lstlast(pass);
// 	printf("\n\n%s ", (char *)last->content);
// 	printf("\n\n   after delone   \n\n");

// 	while (current->next != last)
// 		current = current->next;
// 	current->next = NULL;
// 	ft_lstdelone(last, del);
// 	current = *lst;
// 	while (current)
// 	{
// 		printf("\n %s \n", (char *)current->content);
// 		printf("\n %p \n", (char *)current);
// 		current = current->next;
// 	}
// }