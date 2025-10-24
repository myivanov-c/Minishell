/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:08:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/24 17:31:05 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **filtered_array_multi(char *str)
{
    char     **res;

    res = ft_split(str, '*');
    if (!res)
        return (NULL);
    return (res);
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
        if (select_wildcard_mode(entry->d_name, res, str))
            count++;
        entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}

int     copy_line_if_valid_multi(char **dst, struct dirent *entry, int k, char **res, char *str)
{
    int     j;
    int     len;

    j = 0;
    if (!select_wildcard_mode(entry->d_name, res, str))
        return (0);
    len = ft_strlen(entry->d_name);
    dst[k] = malloc(sizeof(char) * (len + 1));
    if (!dst[k])
        return (-1);
    while (j < len)
    {
        dst[k][j] = entry->d_name[j];
        j++;
    }
    dst[k][j] = '\0';
    return (1);
}

int     fill_filtered_array_multi(char **dst, struct dirent *entry, char **res, char *str)
{
    int     k;
    int     result;
    DIR     *dir = opendir(".");
    if (!dir)
        return (0);
    entry = readdir(dir);
    k = 0;
    while (entry != NULL)
    {
        result = copy_line_if_valid_multi(dst, entry, k, res, str);
        if (result == -1)
        {
            free_array(dst, k);
            return (-1);
        }
        if (result == 1)
            k++;
        entry = readdir(dir);
    }
    dst[k] = NULL;
    closedir(dir);
    return (0);
}

char    **total_filtered_outcomes_multi(struct dirent *entry, char *str, char **res)
{
    char    **filtered;
    int     valid;

    valid = how_many_files_are_valid_multi(str, entry, res);
    filtered = malloc(sizeof(char *) * (valid + 1));
    if (!filtered)
        return (NULL);
    if (fill_filtered_array_multi(filtered, entry, res, str) == -1)
    {
        free_array(filtered, valid);
        return (NULL);
    }
    sort_array(filtered);
    return (filtered);
}

int     main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    int     mode;
    char    **res;
    char    **total_filter;
    struct  dirent *entry = NULL;
    int     i;
    int     is_present;
    
    is_present = check_presence_of_wildcard(argv[1]);
    if (is_present == 0)
        return (0);
    mode = filter_mode(argv[1]);
    printf("Mode is %d\n", mode);
    res = filtered_array_multi(argv[1]);
    total_filter = total_filtered_outcomes_multi(entry, argv[1], res);
    i = 0;
    while (total_filter[i] != NULL)
    {
        printf("In pos %i I have: %s\n", i, total_filter[i]);
        i++;
    }
    return (0);
}