/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:08:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/26 22:03:55 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     how_many_files_are_valid_multi(char **res, int mode)
{
    int     count;
    DIR     *dir;
    struct dirent   *entry;
    
    dir = opendir(".");
    if (!dir)
    {
        perror("opendir");
        return (0);
    }
    entry = readdir(dir);
    count = 0;
    while (entry != NULL)
    {
        if (select_wildcard_mode(entry->d_name, res, mode))
            count++;
        entry = readdir(dir);
    }
    closedir(dir);
    return (count);
}

int copy_line_if_valid_multi(char **slot, struct dirent *entry, char **res, int mode)
{
    int j;
    int len;

    if (!slot)
        return (0);
    if (!select_wildcard_mode(entry->d_name, res, mode))
        return (0);
    len = ft_strlen(entry->d_name);
    *slot = malloc(len + 1);
    if (!*slot)
        return (-1);
    j = 0;
    while (j < len)
    {
        (*slot)[j] = entry->d_name[j];
        j++;
    }
    (*slot)[j] = '\0';
    return (1);
}


int fill_filtered_array_multi(char **dst, char **res, int mode)
{
    DIR                 *dir;
    struct dirent       *entry;
    int                 k;
    int                 result;

    if (!dst)
        return (-1);
    dir = opendir(".");
    if (!dir)
        return (-1);
    k = 0;
    entry = readdir(dir);
    while (entry != NULL)
    {
        result = copy_line_if_valid_multi(&dst[k], entry, res, mode);
        if (result == -1)
            return (closedir(dir), -1);
        if (result == 1)
            k++;
        entry = readdir(dir);
    }
    dst[k] = NULL;
    closedir(dir);
    return (0);
}


char    **total_filtered_outcomes_multi(char *str)
{
    char            **filtered;
    char            **res;
    int             valid;
    int             mode;

    if (!str || !str[0])
        return (NULL);
    mode = filter_mode(str);
    res = ft_split(str, '*');
    if (!res)
        return (NULL);
    valid = how_many_files_are_valid_multi(res, mode);
    filtered = malloc(sizeof(char *) * (valid + 1));
    if (!filtered)
        return (free_array_split(res), NULL);
    if (fill_filtered_array_multi(filtered, res, mode) == -1)
    {
        free_array_n(filtered, valid);
        free_array_split(res);
        return (NULL);
    }
    free_array_split(res);
    sort_array(filtered);
    return (filtered);
}

int     calculate_size_of_new_array(char **original, char **to_append)
{
    int     count_ori;
    int     count_ap;
    int     size;
    
    count_ori = 0;
    count_ap = 0;
    while (original[count_ori] != NULL)
        count_ori++;
    while (to_append[count_ap] != NULL)
        count_ap++;
    size = count_ori + count_ap;
    return (size);
}

void    copy_original(char **original, char **new_array, int *i)
{
    size_t  j;
    size_t  len;
    int     k;

    k = 0;
    while (original[k] != NULL)
    {
        len = ft_strlen(original[k]);
        new_array[*i] = malloc(sizeof(char) * (len + 1));
        if (!new_array[*i])
            return ;
        j = 0;
        while (j < len)
        {
            new_array[*i][j] = original[k][j];
            j++;
        }
        new_array[*i][j] = '\0';
        (*i)++;
        k++;
    }
}

void    copy_append(char **to_append, char **new_array, int *i)
{
    size_t  len;
    size_t  j;
    int     k;

    k = 0;
    while (to_append[k] != NULL)
    {
        len = ft_strlen(to_append[k]);
        new_array[*i] = malloc(sizeof(char) * (len + 1));
        if (!new_array[*i])
            return ;
        j = 0;
        while (j < len)
        {
            new_array[*i][j] = to_append[k][j];
            j++;
         }
        new_array[*i][j] = '\0';
        (*i)++;
        k++;
    }
}

char    **append_arrays(char **original, char **to_append)
{
    int     size;
    char    **new_array;
    int     i;

    i = 0;
    size = calculate_size_of_new_array(original, to_append);
    new_array = malloc(sizeof(char *) * (size + 1));
    if (!new_array)
        return (NULL);
    copy_original(original, new_array, &i);
    copy_append(to_append, new_array, &i);
    new_array[i] = NULL;
    free_array_split (original);
    return (new_array);
}


char    **wildcard_engine(char **args)
{
    char    **filtered;
    char    **temp;
    char    **matches;
    int     i;

    i = 0;
    filtered = NULL;
    while (args[i])
    {
        if (check_presence_of_wildcard(args[i]))
        {
            matches = total_filtered_outcomes_multi(args[i]);
            if (!matches)
                return (free_array_split(filtered), NULL);
            if (!filtered)
                filtered = matches;
            else
            {
                temp = append_arrays(filtered, matches);
                free_array_split(matches);
                filtered = temp;
            }
        }
        i++;
    }
    return (filtered);
}

int main(int argc, char **argv)
{
    char **final;
    int i;

    if (argc < 2)
        return (1);

    final = wildcard_engine(argv + 1);
    if (!final)
        return (1);
    i = 0;
    while (final[i])
    {
        printf("In pos %d, I hace in final: %s\n", i,  final[i]);
        free(final[i]);
        i++;
    }
    free(final);
    return (0);
}
