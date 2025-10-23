/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:09:00 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/18 16:40:44 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst || !f)
    {
        return ;
    }
    while (lst != NULL)
    {
        f(lst -> content);
        lst = lst -> next;
    }
}

/*void	to_uppercase(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	main(void)
{
	t_list	*pista = NULL;
	t_list	*carro1;
	t_list	*carro2;
	t_list	*carro3;
	t_list	*tmp;

	carro1 = ft_lstnew(strdup("audi"));
	carro2 = ft_lstnew(strdup("Skoda"));
	carro3 = ft_lstnew(strdup("opel"));

	if (!carro1 || !carro2 || !carro3)
		return (1);
	ft_lstadd_back(&pista, carro1);
	ft_lstadd_back(&pista, carro2);
	ft_lstadd_back(&pista, carro3);

	printf("Antes do ft_lstiter:\n");
	tmp = pista;
	while (tmp != NULL)
	{
		printf("- %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstiter(pista, to_uppercase);
	printf("\nDepois do ft_lstiter:\n");
	tmp = pista;
	while (tmp != NULL)
	{
		printf("- %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&pista, free);
	return (0);
}*/
