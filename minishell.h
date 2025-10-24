/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/24 17:26:51 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "./Libft/libft.h"

void    free_array(char **arr, int k);
int     ft_strcmp(char *s1, char *s2);
void    sort_array(char **arr);
int     check_presence_of_wildcard(char *str);

void    filter_mode_loops(char  *str, int *has_start, int *has_end, int *has_word);
int     filter_mode(char *str);
char    **filtered_array_multi(char *str);
int     filter_mode_1_helper(char *line_to_compare, char **res, char *str);
int     filter_mode_2_helper(char *line_to_compare, char **res, char *str);
int     filter_mode_helper(char *line_to_compare, char **res, char *str);

int     filter_mode_1(char *line_to_compare, char **res, char *str);
int     filter_mode_2(char *line_to_compare, char **res, char *str);
int     filter_mode_3(char *line_to_compare, char **res, char *str);
int     filter_mode_4_and_5(char *line_to_compare, char **res, char *str);

int     select_wildcard_mode(char *line_to_compare, char **res, char *str);
int     how_many_files_are_valid_multi(char *str, struct dirent *entry, char **res);
int     copy_line_if_valid_multi(char **dst, struct dirent *entry, int k, char **res, char *str);
int     fill_filtered_array_multi(char **dst, struct dirent *entry, char **res, char *str);
char    **total_filtered_outcomes_multi(struct dirent *entry, char *str, char **res);

#endif