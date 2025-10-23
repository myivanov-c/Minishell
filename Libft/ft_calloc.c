/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:04:10 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/21 22:18:50 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void     *ft_calloc(size_t count, size_t size)
{
    size_t  i;
    size_t  total;
    void    *ptr;
    unsigned char *p;
    
    if (count != 0 && size != 0 && count >(size_t) - 1 / size)
    {
        return (NULL);
    }
    total = count * size;
    ptr = malloc(total);
    if (!ptr)
    {
        return (NULL);
    }
    i = 0;
    p = (unsigned char *)ptr;
    while (i < total)
    {
        p[i] = 0;
        i++;
    }
    return (ptr);
}

/*int main(void)
{
    int     *arr;
    int     i;

    arr = ft_calloc(5, sizeof(int));
    if (!arr)
    {
        printf("Erro na alocação!\n");
        return (1);
    }
    i = 0;
    while (i < 5)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
        i++;
    }
    free(arr);
    return (0);
}*/

