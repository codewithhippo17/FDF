/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:51 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:52:42 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*ret_lst;
	t_list	*new;
	void	*content;

	ret_lst = NULL;
	current = lst;
	while (current)
	{
		content = f(current->content);
		if (!content)
			return (ft_lstclear(&ret_lst, del), NULL);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&ret_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret_lst, new);
		current = current->next;
	}
	return (ret_lst);
}

// #include <stdio.h>
// void *f(void *content)
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
// 	return (content);
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
// 	printf("\n\n");
// 	current = *lst;

// 	t_list *map = ft_lstmap(current, f, del);
// 	while (map)
// 	{
// 		printf("%s \n", (char *)map->content);
// 		map = map->next;
// 	}
// }