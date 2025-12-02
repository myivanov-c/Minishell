/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:12:00 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:29:39 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst->content));
		else
			new_node = ft_lstnew(NULL);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void	del(void *content){(void)content;}
void	*echo(void *content){return (content);}
int	test_ft_lstmap()
{
	t_list	*lst;
	t_list	*lst2;

	lst = ft_lstnew("abc");
	ft_lstadd_front(&lst, ft_lstnew("abcd"));
	lst2 = ft_lstmap(lst, &echo, &del);
	if (strcmp(lst2->content, "abcd") != 0
		|| strcmp(lst2->next->content, "abc") != 0
		|| lst2->next->next != NULL)
	{
		free(lst->next);
		free(lst);
		return (1);
	}
	free(lst2->next);
	free(lst2);
	return (0);
}
int	main(void)
{
	if (test_ft_lstmap() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstmap());
	printf("\n");
}
 */