/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:46:34 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:13:49 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (-1);
	if (!(*lst))
	{
		*lst = new;
		return (0);
	}
	ft_lstlast(*lst)->next = new;
	return (0);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	test_ft_lstadd_back()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	ft_lstadd_back(&lst, ft_lstnew("abcd"));
	if (strcmp(lst->content, "abc") != 0
		|| strcmp(lst->next->content, "abcd") != 0
		|| lst->next->next != NULL)
	{
		free(lst->next);
		free(lst);
		return (1);
	}
	free(lst->next);
	free(lst);
	return (0);
}
int	main(void)
{
	if (test_ft_lstadd_back() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstadd_back());
	printf("\n");
}
 */