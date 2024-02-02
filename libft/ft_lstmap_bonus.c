/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:45:46 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/06 19:45:50 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	while (lst && f && del)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

/* ============= COMMENT AREA ===============

void* ft_f(void *content)
{
	int x = 0;
	char *str = (char *)content;
	while (str[x])
	{
		str[x] = ft_toupper(str[x]);
		x++;
	}
	return (content);
}
#include <stdio.h>
int main()
{
	t_list *head;
	head = ft_lstnew(ft_strdup("headHelll me medd"));
	t_list *node1;
	node1 = ft_lstnew(ft_strdup("node1"));
	t_list *node2;
	node2 = ft_lstnew(ft_strdup("node2"));
	t_list *node3;
	node3 = ft_lstnew(ft_strdup("node3"));

	ft_lstadd_front(&head, node1);
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	int x = ft_lstsize(node1);
	printf("size before cleanning-> %d\n", x);
	ft_lstmap(node1, ft_f, free);
	while (node1)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
	ft_lstclear(&node1, free);
	x = ft_lstsize(node1);
	printf("size after cleanning-> %d\n", x);
	return (0);
}
*/