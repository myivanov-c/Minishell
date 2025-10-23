/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_sufix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:00:43 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 15:11:34 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_data_size_su(char *str, int *start)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    *start = 0;
    while (str[i] == '*')
        i++;
    if (str[i] != '*')
        *start = i;
    i++;
    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return (count);
}

char    *store_whats_after_wildcard_su(char *str, int start)
{
    char    *filter_data;
    int     i;

    filter_data = malloc(sizeof(char) * filter_data_size_su(str, &start) + 1);
    if (!filter_data)
        return (NULL);
    i = 0;
    start++;
    while (str[start] != '\0')
    {
        filter_data[i] = str[start];
        i++;
        start++;
    }
    filter_data[i] = '\0';
    return (filter_data);
}

int     check_if_file_valid_su(char *line_to_compare, int f_size, char *f_data)
{
    int     i;
    int     count;
    int     result;

    count = 0;
    if (line_to_compare[0] == '.')
        return (0);
    i = ft_strlen(line_to_compare);
    while (count < f_size)
    {
        i--;
        count++;
    }
    result = ft_strncmp(&line_to_compare[i], f_data, f_size);
    if (result != 0)
        return (0);
    return (1);
}

int     how_many_are_valid_su(struct dirent *entry, int f_size, char *f_data)
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
            if (check_if_file_valid_su(entry->d_name, f_size, f_data))
                count++;
            entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}

int copy_line_if_valid_su(char **dst, struct dirent *entry, int k, int f_size, char *f_data)
{
    int     j;
    int     len;

    j = 0;
    if (!check_if_file_valid_su(entry->d_name, f_size, f_data))
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

int fill_filtered_array_su(char **dst, struct dirent *entry, int f_size, char *f_data)
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
        res = copy_line_if_valid_su(dst, entry, k, f_size, f_data);
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

void    sort_array(char **arr)
{
    int     i;
    int     swapped;
    char    *temp;

    if (!arr)
        return ;
    swapped = 1;
    while (swapped)
    {
        i = 0;
        swapped = 0;
        while (arr[i] && arr[i + 1])
        {
            if (ft_strcmp(arr[i], arr[i + 1]) > 0)
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
    }
}

char    **total_filtered_outcomes_sufix(struct dirent *entry, int f_size, char *f_data)
{
    char    **filtered;
    int     valid;

    valid = how_many_are_valid_su(entry, f_size, f_data);
    filtered = malloc(sizeof(char *) * (valid + 1));
    if (!filtered)
        return (NULL);
    if (fill_filtered_array_su(filtered, entry, f_size, f_data) == -1)
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
    int     start = 0;
    char    *filter_data;
    struct dirent *entry = NULL;
    char    **dest;
    int     i;
    
    if (argc < 2)
        return (0);
    if (!check_presence_of_wildcard(argv[1]))
        return (0);
    size = filter_data_size_su(argv[1], &start);
    printf("The size is %d\n", size);
    filter_data = store_whats_after_wildcard_su(argv[1], start);
    dest = total_filtered_outcomes_sufix(entry, size, filter_data);
    i = 0;
    while (dest[i] != NULL)
    {
        printf("What I have in dest is: %s\n", dest[i]);
        i++;
    }
    return (0);
}*/
