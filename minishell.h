/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 22:02:31 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
//# include "./Libft/libft.h"

void    free_array(char **arr, int k);
int     ft_strcmp(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_strncmp(char *s1, char *s2, int n);
int     check_presence_of_wildcard(char *str);
void    sort_array(char **arr);

int     filter_data_size_pre(char *str);
char    *store_wildcard_pre(char *str);
int     check_if_file_valid_pre(char *line_to_compare, int f_size, char *f_data);
int     how_many_files_valid_pre(struct dirent *entry, int f_size, char *f_data);
int     copy_line_if_valid_pre(char **dst, struct dirent *entry, int k, int f_size, char *f_data);
int     fill_filtered_array_pre(char **dst, struct dirent *entry, int f_size, char *f_data);
char    **total_filtered_outcomes_pre(struct dirent *entry, int f_size, char *f_data);

int     filter_data_size_su(char *str, int *start);
char    *store_whats_after_wildcard_su(char *str, int start);
int     check_if_file_valid_su(char *line_to_compare, int f_size, char *f_data);
int     how_many_are_valid_su(struct dirent *entry, int f_size, char *f_data);
int     copy_line_if_valid_su(char **dst, struct dirent *entry, int k, int f_size, char *f_data);
int     fill_filtered_array_su(char **dst, struct dirent *entry, int f_size, char *f_data);
char    **total_filtered_outcomes_sufix(struct dirent *entry, int f_size, char *f_data);

int     scan_argument(char *str);
void     sufix_mode(char *str);
void    prefix_mode(char *str);

#endif