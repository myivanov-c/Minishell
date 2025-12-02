/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:45:43 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:50:11 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include "../minishell.h"

typedef struct s_token	t_token;

t_token	*new_token(char const *line, int len);
t_token	*dup_token(t_token *old_token);
void	free_token(void *ptr);
int		count_tokens(t_list *tokens);

int		fill_token_flags(t_token *token);
int		special_fill_token_flags(t_token *token, char quoted);

t_list	*split_token(t_token *token);

char	**get_argv_tokenlst(t_list *tokens);

#endif