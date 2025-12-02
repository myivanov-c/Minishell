/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:55:22 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:25:43 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
/* 
#include <stdlib.h>
#include <stdio.h>
void	del(void *content){(void)content;}
int	test_ft_lstdelone()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	ft_lstadd_back(&lst, ft_lstnew("abcd"));
	ft_lstdelone(lst->next, &del);
	ft_lstdelone(lst, &del);
	return (0);
}
int	main(void)
{
	if (test_ft_lstdelone() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstdelone());
	printf("\n");
}
 */