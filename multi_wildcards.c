/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:08:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/27 13:35:36 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int how_many_files_are_valid_multi(t_wildcard *w)
{
	int                 count;
	DIR                 *dir;
	struct dirent       *entry;

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
		if (select_wildcard_mode(entry->d_name, w))
			count++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}


int copy_line_if_valid_multi(char **slot, struct dirent *entry, t_wildcard *w)
{
	int j;
	int len;

	if (!slot)
		return (0);
	if (!select_wildcard_mode(entry->d_name, w))
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

int fill_filtered_array_multi(char **dst, t_wildcard *w)
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
		result = copy_line_if_valid_multi(&dst[k], entry, w);
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

char **total_filtered_outcomes_multi(char *str)
{
	t_wildcard	w;
	char		**filtered;
	int			valid;

	if (!str || !str[0])
		return (NULL);
	w.pattern = str;
	w.mode = filter_mode(str);
	w.split_chars = ft_split(str, '*');
	if (!w.split_chars)
		return (NULL);
	valid = how_many_files_are_valid_multi(&w);
	filtered = malloc(sizeof(char *) * (valid + 1));
	if (!filtered)
		return (free_array_split(w.split_chars), NULL);
	if (fill_filtered_array_multi(filtered, &w) == -1)
	{
		free_array_n(filtered, valid);
		free_array_split(w.split_chars);
		return (NULL);
	}
	free_array_split(w.split_chars);
	sort_array(filtered);
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
