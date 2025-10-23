/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:44:09 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 15:43:22 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void     ft_skip_space(const char *str, size_t *i)
{
    while (str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\v' ||
    str[*i] == '\r' || str[*i] == '\f' || str[*i] == ' ')
    {
        (*i)++;
    }
}

int    ft_count_minus(const char *str, size_t *i)
{
    int  count_minus = 0;
    
    while (str[*i] == '+' || str[*i] == '-')
    {
        if (str[*i] == '-') 
        {
            count_minus++;
        }
        (*i)++;
        if (str[*i] == '+' || str[*i] == '-')
        {
            return (0); 
        }
    }
    return (count_minus);
}

int     ft_atoi(const char *str)
{
    size_t  i = 0;
    int     count_minus;
    int     result = 0;
    
    ft_skip_space(str, &i);
    count_minus = ft_count_minus(str, &i);
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    if (count_minus == 1)
    {
        return (-result);
    }
    return (result);
}

/*int     main(void)
{
    char    str[] = "       132456a";
    int     result = ft_atoi(str);

    printf("Resultado: %d\n", result);
}*/
