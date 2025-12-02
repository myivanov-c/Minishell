/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:38:05 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:04:31 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	test_ft_lstlast()
{
	t_list	*lst = NULL;

	if (ft_lstlast(lst) != NULL)
		return (1);
	lst = ft_lstnew("abc");
	if (ft_lstlast(lst) != lst)
	{
		free(lst);
		return (2);
	}
	ft_lstadd_front(&lst, ft_lstnew("abcd"));
	if (ft_lstlast(lst) != lst->next)
	{
		free(lst->next);
		free(lst);
		return (3);
	}
	free(lst->next);
	free(lst);
	return (0);
}
int	main(void)
{
	if (test_ft_lstlast() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstlast());
	printf("\n");
}
 */