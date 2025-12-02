/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:53:07 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 11:22:24 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

int	is_redirection_token(char *str)
{
	return (ft_strcmp(str, "<") == 0
		|| ft_strcmp(str, "<<") == 0
		|| ft_strcmp(str, ">") == 0
		|| ft_strcmp(str, ">>") == 0);
}

int	is_word_token(char *s)
{
	return (s
		&& ft_strcmp(s, "(") != 0
		&& ft_strcmp(s, ")") != 0
		&& !is_operator_str(s)
		&& !is_redirection_token(s));
}

int	redir_followup_status(t_list *node)
{
	t_list	*nextn;
	t_token	*next;

	nextn = node->next;
	if (!nextn)
		return (2);
	next = (t_token *)nextn->content;
	if (!next || !next->str)
		return (2);
	if (!is_word_token(next->str) || is_redirection_token(next->str))
		return (1);
	return (0);
}

int	has_invalid_redirection_sequences(t_list *tokens)
{
	t_token	*tk;
	int		st;

	while (tokens)
	{
		tk = (t_token *)tokens->content;
		if (tk && tk->str && is_redirection_token(tk->str))
		{
			st = redir_followup_status(tokens);
			if (st)
				return (st);
		}
		tokens = tokens->next;
	}
	return (0);
}
