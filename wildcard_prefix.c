/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:38:13 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 22:09:05 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_data_size_pre(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '*')
        i++;
    return (i);
}

char    *store_wildcard_pre(char *str)
{
    char    *filter;
    int     size;
    int     i;

    size = filter_data_size_pre(str);
    filter = malloc(sizeof(char) * (size + 1));
    if (!filter)    
        return (NULL);
    i = 0;
    while (i < size)
    {
        filter[i] = str[i];
        i++;
    }
    filter[i] = '\0';
    return (filter);
}

int     check_if_file_valid_pre(char *line_to_compare, int f_size, char *f_data)
{
    int     i;

    if (line_to_compare[0] == '.')
        return (0);
    i = 0;
    if (ft_strncmp(&line_to_compare[i], f_data, f_size) != 0)
        return (0);
    return (1);
}

int     how_many_files_valid_pre(struct dirent *entry, int f_size, char *f_data)
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
        if (check_if_file_valid_pre(entry->d_name, f_size, f_data) == 1)
            count++;
        entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}

int copy_line_if_valid_pre(char **dst, struct dirent *entry, int k, int f_size, char *f_data)
{
    int     j;
    int     len;

    j = 0;
    if (!check_if_file_valid_pre(entry->d_name, f_size, f_data))
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

int fill_filtered_array_pre(char **dst, struct dirent *entry, int f_size, char *f_data)
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
        res = copy_line_if_valid_pre(dst, entry, k, f_size, f_data);
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

char    **total_filtered_outcomes_pre(struct dirent *entry, int f_size, char *f_data)
{
    char    **filtered;
    int     valid;

    valid = how_many_files_valid_pre(entry, f_size, f_data);
    filtered = malloc(sizeof(char *) * (valid + 1));
    if (!filtered)
        return (NULL);
    if (fill_filtered_array_pre(filtered, entry, f_size, f_data) == -1)
    {
        free_array(filtered, valid);
        return (NULL);
    }
    sort_array(filtered);
    return (filtered);
}

/*int     main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    int     count;
    char    *stored;
    char    *file = "filterbro";
    int     valid_status;
    int     how_many_files_valid;
    struct dirent *entry = NULL;
    int     i;
    char    **dest;

    if (!check_presence_of_wildcard_pre(argv[1]))
        return (0);
    count = filter_data_size_pre(argv[1]);
    printf("%d\n", count);
    stored = store_wildcard_pre(argv[1]);
    printf("Stored: %s\n", stored);
    valid_status = check_if_file_valid_pre(file, count, stored);
    printf("%d\n", valid_status);
    how_many_files_valid = how_many_files_valid_pre(entry, count, stored);
    printf("Files valid: %d\n", how_many_files_valid );
    dest = total_filtered_outcomes_pre(entry, count, stored);
    i = 0;
    while (dest[i] != NULL)
    {
        printf("In position %d of dest I have: %s\n", i, dest[i]);
        i++;
    }
    free (stored);
    return (0);
}*/