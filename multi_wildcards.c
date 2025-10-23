/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:08:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 17:56:41 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **filtered_array(char *str)
{
    char     **res;

    res = ft_split(str, '*');
    if (!res)
        return (NULL);
    return (res);
}

int     check_if_line_valid_multi(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = filtered_array(str);
    if (!res)
    {
        free(res);
        return (0);
    }
    while (line_to_compare[i] != '\0')
    {
        if (res[j] != NULL)
        {
            if (ft_strncmp(&line_to_compare[i], res[j], ft_strlen(res[j])) == 0)
                j++;
        }
        i++;
    }
    if (res[j] == NULL)
        return (1);
    return (0);
    
}

int     how_many_files_are_valid_multi(char *str, struct dirent *entry, char **res)
{
    int     count;
    DIR *dir = opendir(".");
    
    if (!dir)
    {
        perror("opendir");
        return (0);
    }
    entry = readdir(dir);
    count = 0;
    while (entry != NULL)
    {
        if (check_if_line_valid_multi(entry->d_name, res, str))
            count++;
        entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}



int     main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    char    **filtered;
    int     i;
    int     how;
    struct dirent *entry = NULL;

    filtered = filtered_array(argv[1]);
    i = 0;
    while (filtered[i] != NULL)
    {
        printf("My filtered array: %s\n", filtered[i]);
        i++;
    }
    how = how_many_files_are_valid_multi(argv[1], entry, filtered);
    printf("%d\n", how);
    return (0);
}