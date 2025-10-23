/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:49:12 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 18:14:44 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putendl_fd(char *s, int fd)
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
    write(fd, "\n", 1);
}

/*int     main(void)
{
    char    s[] = "Koenigsegg CC850";

    ft_putendl_fd(s, 1);
    return (0);
}*/