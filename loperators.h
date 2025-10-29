/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loperators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:59:34 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/29 12:17:11 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOPERATORS_H
 #define LOPERATORS_H

#include <unistd.h>
#include <stdio.h>
#include "./Libft/libft.h"

//smart split
int     is_space(char c);
int     handle_operator_split(char *str, char **result, size_t *j, size_t *word_i);
int     handle_word_split(char *str, char **result, size_t *j, size_t *word_i);
void    remove_spaces(char *str, size_t *i);
int     smart_array_size(char *str);
int     is_not_delimiter(char *str, size_t *j);
char    *allocate_word(char *str, size_t start, size_t end);
int     smart_loop(char *str, char **result);
char	**smart_split(char *str);

#endif