/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:35:35 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:03:05 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	test_ft_lstsize()
{
	t_list	*lst = NULL;

	if (ft_lstsize(lst) != 0)
		return (1);
	lst = ft_lstnew("abc");
	if (ft_lstsize(lst) != 1)
	{
		free(lst);
		return (2);
	}
	ft_lstadd_front(&lst, ft_lstnew("abcd"));
	if (ft_lstsize(lst) != 2)
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
	if (test_ft_lstsize() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstsize());
	printf("\n");
}
 */