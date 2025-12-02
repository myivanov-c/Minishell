/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:21:27 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:14:25 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (-1);
	new->next = *lst;
	*lst = new;
	return (0);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	test_ft_lstadd_front()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	ft_lstadd_front(&lst, ft_lstnew("abcd"));
	if (strcmp(lst->content, "abcd") != 0
		|| strcmp(lst->next->content, "abc") != 0
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
	if (test_ft_lstadd_front() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstadd_front());
	printf("\n");
}
 */