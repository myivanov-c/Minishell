/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 16:58:02 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "../Libft/libft.h"

typedef struct s_wildcard
{
	char	*pattern;
	char	**split_chars;
	int		mode;
}	        t_wildcard;

void    free_array_split(char **arr);
void    free_array_n(char **arr, int n);
int     ft_strcmp(char *s1, char *s2);
void    sort_array(char **arr);
int     all_strings_empty(t_wildcard *w);
int     check_presence_of_wildcard(char *str);

int     pattern_allows_hidden(t_wildcard *w);

void    filter_mode_loops(char  *str, int *has_start, int *has_end, int *has_word);
int     filter_mode(char *str);
int     filter_mode_1_helper(char *line_to_compare, t_wildcard *w);
int     filter_mode_2_helper(char *line_to_compare, t_wildcard *w);
int     filter_mode_helper(char *line_to_compare, t_wildcard *w);

int     filter_mode_1(char *line_to_compare, t_wildcard *w);
int     filter_mode_2(char *line_to_compare, t_wildcard *w);
int     filter_mode_3(char *line_to_compare, t_wildcard *w);
int     filter_mode_4_and_5(char *line_to_compare, t_wildcard *w);

int     select_wildcard_mode(char *line_to_compare, t_wildcard *w);
int     how_many_files_are_valid_multi(t_wildcard *w);
int     copy_line_if_valid_multi(char **slot, struct dirent *entry, t_wildcard *w);
int     fill_filtered_array_multi(char **dst, t_wildcard *w);
char    **total_filtered_outcomes_multi(char *str);

int     calculate_size_of_new_array(char **original, char **to_append);
void    copy_original(char **original, char **new_array, int *i);
void    copy_append(char **to_append, char **new_array, int *i);
char    **append_arrays(char **original, char **to_append);
void    append_matches(char ***filtered, char **matches);
char    **wildcard_engine(char **args);

#endif