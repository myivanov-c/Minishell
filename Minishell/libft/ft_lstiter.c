/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:05:12 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:27:19 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void	put(void *content){ft_putendl_fd(content, 1);}
int	test_ft_lstiter()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	ft_lstadd_front(&lst, ft_lstnew("abcd"));
	ft_lstiter(lst, &put);
	free(lst->next);
	free(lst);
	return (0);
}
int	main(void)
{
	if (test_ft_lstiter() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstiter());
	printf("\n");
}
 */