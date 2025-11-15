/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loperators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:59:34 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/07 19:02:12 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOPERATORS_H
 #define LOPERATORS_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../Wildcards/wildcards.h"

typedef struct  s_split_org
{
    char    *cmd;
    char    *arg;
    char    *op;
    char    *open_p;
    char    *close_p;
}           t_split_org;

//smart_split_helpers.c
int     is_space(char c);
int     is_logical_operator(char *str, size_t i);
void    remove_spaces(char *str, size_t *i);
int     handle_operator_split(char *str, char **result, size_t *j, size_t *word_i);
int     handle_word_split(char *str, char **result, size_t *j, size_t *word_i);

//split_small_helpers.c
int     is_parenthesis(char c);
void	skip_word(char *str, size_t *i);
int     is_not_delimiter(char *str, size_t i);
char    *allocate_word(char *str, size_t start, size_t end);;

//smart_split.c
int     smart_array_size(char *str);
int     last_token_is_operator(char **res);
int     handle_token(char *str, char **res, size_t *j, size_t *w_i);
int     smart_loop(char *str, char **result);
char	**smart_split(char *str);

//logical_helpers.c
int     is_operator(char *s);
int     is_paren(char *s);
int     has_operator(char **str, int i);

//logical_checker.c
int     parentheses_are_balanced(char **res);
int     check_for_logical_operators(char **res);
int     is_syntax_valid(char **tokens);
int     check_adjacent_operators(char **res);
int     check_if_logical_mode(char *str);

#endif