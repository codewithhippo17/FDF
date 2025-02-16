/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:06 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 18:19:13 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
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

// 	char first2[] = "code ";
// 	new = ft_lstnew(first2);
// 	ft_lstadd_front(lst, new);

// 	t_list *curent = *lst;
// 	printf("%d \n", ft_lstsize(curent));
// 	printf("%s \n", (char *)(*lst)->content);
// 	printf("%s \n", (char *)(*lst)->next->content);
// 	printf("%s \n", (char *)(*lst)->next->next->content);
// 	printf("%s \n", (char *)(*lst)->next->next->next);
// }