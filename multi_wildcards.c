/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:08:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/24 16:40:54 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    filter_mode_loops(char  *str, int *has_star_start, int *has_star_end, int *has_word)
{
    int     i;

    i = 0;
    while (str[i] == '*')
    {
        *has_star_start = 1;
        i++;
    }
    while (str[i] && str[i] != '*')
    {
        *has_word = 1;
        i++;
    }
    while (str[i])
    {
        if (str[i] == '*' && str[i + 1] == '\0')
            *has_star_end = 1;
        i++;
    }
}

int     filter_mode(char *str)
{
    int     has_star_start;
    int     has_star_end;
    int     has_word;
    int     mode;
    
    mode = -1;
    has_star_start = 0;
    has_star_end = 0;
    has_word = 0;
    filter_mode_loops(str, &has_star_start, &has_star_end, &has_word);
    if (has_star_start && has_word && !has_star_end) // *abc*das
        mode = 1;
    else if (!has_star_start && has_word && has_star_end) // abc*asd*
        mode = 2;
    else if (!has_star_start && has_word && !has_star_end) // abs*ads
        mode = 3;
    else if (has_star_start && has_word && has_star_end) // *ada*das*
        mode = 4;
    else if (has_star_start && !has_word) // ***
        mode = 5;
    return (mode);
}

char    **filtered_array_multi(char *str)
{
    char     **res;

    res = ft_split(str, '*');
    if (!res)
        return (NULL);
    return (res);
}

int     filter_mode_1_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     count;;
    int     res_count;
    int     size;
    
    res = filtered_array_multi(str);
    if (!res)
        return (0);
    res_count = 0;
    count = 0;
    while (res[res_count + 1] != NULL)
        res_count++;
    i = ft_strlen(line_to_compare);
    size = ft_strlen(res[res_count]);
    while (count < size)
    {
        i--;
        count++;
    }
    if (ft_strncmp(&line_to_compare[i], res[res_count], size) == 0)
        return (1);
    return (0);
}

int     filter_mode_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = filtered_array_multi(str);
    if (!res)
    {
        free(res);
        return (0);
    }
    while (line_to_compare[i] != '\0')
    {
        if (res[j] != NULL && ft_strncmp(&line_to_compare[i], res[j], ft_strlen(res[j])) == 0)
        {
            i = i + ft_strlen(res[j]) - 1;
            j++;
        }
        else
            i++;
    }
    if (res[j] == NULL)
        return (1);
    return (0);
}

int     filter_mode_1(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;

    result_first = filter_mode_1_helper(line_to_compare, res, str);
    result_second = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_2_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     res_size;

    res = ft_split(str, '*');
    if (line_to_compare[0] == '.')
        return (0);
    res_size = ft_strlen(res[0]);
    i = 0;
    if (ft_strncmp(&line_to_compare[i], res[0], res_size) != 0)
        return (0);
    return (1);
}

int     filter_mode_2(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;
    
    result_first = filter_mode_2_helper(line_to_compare, res, str);
    result_second = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_3(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;
    int     result_third;

    result_first = filter_mode_1_helper(line_to_compare, res, str);
    result_second = filter_mode_2_helper(line_to_compare, res, str);
    result_third = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1 && result_third == 1)
        return (1);
    return (0);
}

int     filter_mode_4_and_5(char *line_to_compare, char **res, char *str) // *ada*das*
{
    int     result;

    if (line_to_compare[0] == '.')
        return (0);
    result = filter_mode_helper(line_to_compare, res, str);
    if (result == 1)
        return (1);
    return (0);
}

int     select_wildcard_mode(char *line_to_compare, char **res, char *str)
{
    int     mode;
    
    mode = filter_mode(str);
    if (mode == 1)
        return (filter_mode_1(line_to_compare, res, str));
    else if (mode == 2)
        return (filter_mode_2(line_to_compare, res, str));
    else if (mode == 3)
        return (filter_mode_3(line_to_compare, res, str));
    else if (mode == 4 || mode == 5)
        return (filter_mode_4_and_5(line_to_compare, res, str));
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