/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:58:17 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:25:49 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/* 
#include <stdlib.h>
#include <stdio.h>
void	del(void *content){(void)content;}
int	test_ft_lstclear()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	ft_lstadd_back(&lst, ft_lstnew("abcd"));
	ft_lstclear(&lst, &del);
	return (0);
}
int	main(void)
{
	if (test_ft_lstclear() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstclear());
	printf("\n");
}
 */