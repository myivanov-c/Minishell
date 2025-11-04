/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:46:05 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:33:50 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_token
{
	char	*str;
	char	*quote_flags;
}	t_token;
// quote_flags 0 = normal
// quote_flags 39 (') = literal
// quote_flags 34 (") = half literal

t_list		*tokenize(char const *line);

t_cmdtree	*create_cmdtree(t_list *tokens);
int			expand_envs(t_cmdtree *cmdtree);
int			expand_wilds(t_cmdtree *cmdtree);
int			remove_quotes(t_cmdtree *cmdtree);

t_token		*new_token(char const *line, int len);
t_token		*dup_token(t_token *old_token);
int			fill_token_flags(t_token *token);
void		free_token(void *token);


int     ft_isspace(char c);

#endif