/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paren_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 10:50:52 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

int	has_unmatched_closing_paren(t_list *tokens)
{
	int		depth;
	t_token	*tk;

	depth = 0;
	while (tokens)
	{
		tk = (t_token *)tokens->content;
		if (tk && tk->str)
		{
			if (ft_strcmp(tk->str, "(") == 0)
				depth++;
			else if (ft_strcmp(tk->str, ")") == 0)
			{
				depth--;
				if (depth < 0)
					return (
						ft_dprintf(2,
							"syntax error near unexpected token `)'\n"), 1);
			}
		}
		tokens = tokens->next;
	}
	return (0);
}

int	parens_are_fully_closed(t_list *tokens)
{
	int		depth;
	t_token	*tk;

	depth = 0;
	while (tokens)
	{
		tk = (t_token *)tokens->content;
		if (tk && tk->str)
		{
			if (ft_strcmp(tk->str, "(") == 0)
				depth++;
			else if (ft_strcmp(tk->str, ")") == 0)
				depth--;
		}
		tokens = tokens->next;
	}
	return (depth == 0);
}

int	is_invalid_open_paren(t_token *prev, t_token *curr, t_token *next)
{
	if (!curr || !curr->str)
		return (0);
	if (ft_strcmp(curr->str, "(") != 0)
		return (0);
	if (prev && prev->str)
	{
		if (!is_operator_str(prev->str) && ft_strcmp(prev->str, "(") != 0)
			return (1);
	}
	if (next && next->str)
	{
		if (is_operator_str(next->str))
			return (1);
	}
	return (0);
}

int	is_invalid_close_paren(t_token *curr, t_token *next)
{
	if (!curr || !curr->str)
		return (0);
	if (ft_strcmp(curr->str, ")") != 0)
		return (0);
	if (!next || !next->str)
		return (0);
	if (!is_operator_str(next->str)
		&& !is_redirection_token(next->str)
		&& ft_strcmp(next->str, ")") != 0)
	{
		return (1);
	}
	return (0);
}

int	has_invalid_paren_sequences(t_list *tokens)
{
	t_token	*prev;
	t_token	*curr;
	t_token	*next;

	prev = NULL;
	while (tokens)
	{
		curr = (t_token *)tokens->content;
		if (tokens->next)
			next = (t_token *)tokens->next->content;
		else
			next = NULL;
		if (is_invalid_open_paren(prev, curr, next))
			return (
				ft_dprintf(2,
					"syntax error near unexpected token `%s'\n", curr->str), 1);
		if (is_invalid_close_paren(curr, next))
			return (
				ft_dprintf(2,
					"syntax error near unexpected token `%s'\n", curr->str), 1);
		prev = curr;
		tokens = tokens->next;
	}
	return (0);
}
