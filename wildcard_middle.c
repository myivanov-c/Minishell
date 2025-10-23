/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_middle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:40:52 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 14:41:24 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_data_size_mid(char *str, int *start)
{
    int     i;
    int     count;

    i = 0;
    while (str[i] == '*')
        i++;
    *start = i;
    count = 0;
    while (str[i] != '*')
    {
        count++;
        i++;
    }
    return (count);
}

char    *store_whats_in_wildcard_mid(char *str, int start)
{
    char    *f_data;
    int     size;
    int     i;
    
    size = filter_data_size_mid(str, &start);
    f_data = malloc(sizeof(char) * (size + 1));
    if (!f_data)
        return (NULL);
    i = 0;
    while (i < size)
    {
        f_data[i] = str[start];
        i++;
        start++;
    }
    f_data[i] = '\0';
    return (f_data);
}

int     check_if_file_valid_mid(char *line_to_compare, int f_size, char *f_data)
{
    int     i;
    int     valid;

    if (line_to_compare[0] == '.')
        return (0);
    i = 0;
    valid = 0;
    while (line_to_compare[i] != '\0')
    {
        if (ft_strncmp(&line_to_compare[i], f_data, f_size) == 0)
        {
            valid = 1;
            break ;
        }
        else
            i++;
    }
    return (valid);
}

int     how_many_are_valid_mid(struct dirent *entry, int f_size, char *f_data)
{
    int     count;
    DIR *dir = opendir(".");
    
    if (!dir)
    {
        perror("opendir");
        return (0);
    }
    count = 0;
    entry = readdir(dir);
    while (entry != NULL)
    {
            if (check_if_file_valid_mid(entry->d_name, f_size, f_data))
                count++;
            entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}

int copy_line_if_valid_mid(char **dst, struct dirent *entry, int k, int f_size, char *f_data)
{
    int     j;
    int     len;

    j = 0;
    if (!check_if_file_valid_mid(entry->d_name, f_size, f_data))
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

int     fill_filtered_array_mid(char **dst, struct dirent *entry, int f_size, char *f_data)
{
    int     k;
    int     res;
    DIR     *dir = opendir(".");
    
    if (!dir)
        return (0);
    entry = readdir(dir);
    k = 0;
    while (entry != NULL)
    {
        res = copy_line_if_valid_mid(dst, entry, k, f_size, f_data);
        if (res == -1)
        {
            free_array(dst, k);
            return (-1);
        }
        if (res == 1)
            k++;
        entry = readdir(dir);
    }
    dst[k] = NULL;
    closedir(dir);
    return (0);
}

char    **total_filtered_outcomes_mid(struct dirent *entry, int f_size, char *f_data)
{
    char    **filtered;
    int     valid;

    valid = how_many_are_valid_mid(entry, f_size, f_data);
    filtered = malloc(sizeof(char *) * (valid + 1));
    if (!filtered)
        return (NULL);
    if (fill_filtered_array_mid(filtered, entry, f_size, f_data) == -1)
    {
        free_array(filtered, valid);
        return (NULL);
    }
    sort_array(filtered);
    return (filtered);
}

/*int     main(int argc, char **argv)
{
    int     size;
    char    *filter;
    int     start = 0;
    struct dirent *entry = NULL;
    char    **filtered_array;
    int     i;
    
    if (argc < 2)
        return (0);
    size = filter_data_size_mid(argv[1], &start);
    printf("Size: %d\n", size);
    filter = store_whats_in_wildcard_mid(argv[1], start);
    printf("%s\n", filter);
    filtered_array = total_filtered_outcomes_mid(entry, size, filter);
    i = 0;
    while (filtered_array[i] != NULL)
    {
        printf("Na posição %d tenho: %s\n", i + 1, filtered_array[i]);
        i++;
    }
    free(filter);
    return (0);
}*/