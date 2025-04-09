/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:24:10 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:52:23 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main()
// {
// 	t_list **lst = malloc(sizeof(t_list *));
// 	t_list *new;

// 	char str[] = "code";
// 	*lst = ft_lstnew(str);

// 	char first[] = "hippo";
// 	new = ft_lstnew(first);
// 	ft_lstadd_front(lst, new);

// 	char first1[] = "gggg";
// 	new = ft_lstnew(first1);
// 	ft_lstadd_front(lst, new);

// 	printf("%s \n", (char *)(*lst)->content);
// 	printf("%s \n", (char *)(*lst)->next->content);
// 	printf("%s \n", (char *)(*lst)->next->next->content);
// 	printf("%s \n", (char *)(*lst)->next->next->next);
// }
