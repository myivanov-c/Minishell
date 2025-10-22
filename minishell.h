/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 15:37:40 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
//# include "./Libft/libft.h"

//wildcards

void    free_array(char **arr, int k);
int     ft_strcmp(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_strncmp(char *s1, char *s2, int n);
int     check_presence_of_wildcard(char *str);
int     filter_data_size(char *str, int *start);
char    *store_whats_after_wildcard(char *str, int start);
int     check_if_file_valid(char *line_to_compare, int f_size, char *f_data);
int     how_many_are_valid(struct dirent *entry, int f_size, char *f_data);
int     copy_line_if_valid(char **dst, struct dirent *entry, int k, int f_size, char *f_data);
int     fill_filtered_array(char **dst, struct dirent *entry, int f_size, char *f_data);
void    sort_array(char **arr);
char    **total_filtered_outcomes_sufix(struct dirent *entry, int f_size, char *f_data);


#endif