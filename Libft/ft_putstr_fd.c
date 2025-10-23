/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:41:07 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 17:48:24 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr_fd(char *s, int fd)
{
    int     i;

    if (!s)
    {
        return ;
    }
    i = 0;
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
}

/*int     main(void)
{
    char    s[] = "Ferrari Daytona SP3";

    ft_putstr_fd(s, 1);
    return (0);
}*/