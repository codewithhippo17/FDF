/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:48 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:52:06 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

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
// 	printf("%d \n", ft_lstsize(curent));
// 	printf("%s \n", (char *)(*lst)->content);
// 	printf("%s \n", (char *)(*lst)->next->content);
// 	printf("%s \n", (char *)(*lst)->next->next->content);
// 	printf("%p \n", (char *)(*lst)->next->next->next);	
// 	printf("%s \n", (char *)(*lst)->next->next->next->content);
// 	printf("%p \n", (char *)(*lst)->next->next->next->next);
// }