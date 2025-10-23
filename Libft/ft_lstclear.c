/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:03 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/18 16:39:42 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *current;
    t_list  *temp;

    if (!lst || !del)
    {
        return ;
    }
    current = *lst;
    while (current != NULL)
    {
        temp = current;
        current = current -> next;
        del (temp -> content);
        free (temp);
    }
    *lst = NULL;
}

/*void	ft_del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*pista = NULL;
	t_list	*carro1;
	t_list	*carro2;
	t_list	*carro3;

	
	char *marca1 = ft_strdup("Huayra");
	char *marca2 = ft_strdup("Jesko");
	char *marca3 = ft_strdup("Revuelto");

	if (!marca1 || !marca2 || !marca3)
	{
		printf("Falha ao alocar memória.\n");
		return (1);
	}

	carro1 = ft_lstnew(marca1);
	carro2 = ft_lstnew(marca2);
	carro3 = ft_lstnew(marca3);

	ft_lstadd_back(&pista, carro1);
	ft_lstadd_back(&pista, carro2);
	ft_lstadd_back(&pista, carro3);

	printf("Carros na pista antes de apagar:\n");
	t_list *temp = pista;
	while (temp)
	{
		printf("- %s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&pista, ft_del_content);
	if (pista == NULL)
		printf("Carros apagados.\n");
	else
		printf("Erro: ainda há carros na pista!\n");

	return (0);
}*/
