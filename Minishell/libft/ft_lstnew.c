/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:47:03 by causilva          #+#    #+#             */
/*   Updated: 2025/10/29 13:00:41 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	test_ft_lstnew()
{
	t_list	*lst;

	lst = ft_lstnew("abc");
	if (strcmp(lst->content, "abc") != 0
		|| lst->next != NULL)
	{
		free(lst);
		return (1);
	}
	free(lst);
	return (0);
}
int	main(void)
{
	if (test_ft_lstnew() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_lstnew());
	printf("\n");
}
 */