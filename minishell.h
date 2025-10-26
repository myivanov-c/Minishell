/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/26 20:13:11 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "./Libft/libft.h"

void    free_array_split(char **arr);
void    free_array_n(char **arr, int n);
int     ft_strcmp(char *s1, char *s2);
void    sort_array(char **arr);
int     all_strings_empty(char **res);
int     check_presence_of_wildcard(char *str);

void    filter_mode_loops(char  *str, int *has_start, int *has_end, int *has_word);
int     filter_mode(char *str);
char    **filtered_array_multi(char *str);
int     filter_mode_1_helper(char *line_to_compare, char **res);
int     filter_mode_2_helper(char *line_to_compare, char **res);
int     filter_mode_helper(char *line_to_compare, char **res);

int     filter_mode_1(char *line_to_compare, char **res);
int     filter_mode_2(char *line_to_compare, char **res);
int     filter_mode_3(char *line_to_compare, char **res);
int     filter_mode_4_and_5(char *line_to_compare, char **res);

int     select_wildcard_mode(char *line_to_compare, char **res, int mode);
int     how_many_files_are_valid_multi(char **res, int mode);
int     copy_line_if_valid_multi(char **slot, struct dirent *entry, char **res, int mode);
int     fill_filtered_array_multi(char **dst, char **res, int mode);
char    **total_filtered_outcomes_multi(char *str);

#endif