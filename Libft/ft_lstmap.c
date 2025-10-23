/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:11:41 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/18 16:42:25 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;

    if (!lst || !f || !del)
        return (NULL);
    new_list = NULL;
    while (lst != NULL)
    {
        new_node = ft_lstnew(f(lst -> content));
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst -> next;
    }
    return (new_list);
}

/*void	*str_tolower(void *content)
{
	char	*str = (char *)content;
	size_t	i = 0;
	char	*new = malloc(ft_strlen(str) + 1);

	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = ft_tolower((int)str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	del_str(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*orig = NULL;
	t_list	*mapped;
	t_list	*tmp;

	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("AUDI")));
	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("OPEL")));
	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("RENAULT")));
	printf("Original:\n");
	tmp = orig;
	while (tmp)
	{
		printf(" - %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	mapped = ft_lstmap(orig, str_tolower, del_str);
	if (!mapped)
	{
		printf("Erro ao mapear lista.\n");
		ft_lstclear(&orig, del_str);
		return (1);
	}
	printf("\nNova lista:\n");
	tmp = mapped;
	while (tmp)
	{
		printf(" - %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&orig, del_str);
	ft_lstclear(&mapped, del_str);
	return (0);
}*/