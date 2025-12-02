/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 10:50:31 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

int	is_operator_str(char *str)
{
	return (ft_strcmp(str, "&&") == 0
		|| ft_strcmp(str, "||") == 0
		|| ft_strcmp(str, "|") == 0);
}

int	line_starts_with_op(t_list *line_tokens)
{
	t_token	*tk;

	if (!line_tokens)
		return (0);
	tk = (t_token *)line_tokens->content;
	if (!tk || !tk->str)
		return (0);
	return (is_operator_str(tk->str));
}

int	has_invalid_operator_sequence(t_list *tokens)
{
	t_token	*curr;
	t_token	*next;

	while (tokens && tokens->next)
	{
		curr = (t_token *)tokens->content;
		next = (t_token *)tokens->next->content;
		if (!curr || !next || !curr->str || !next->str)
			return (0);
		if (is_operator_str(curr->str) && is_operator_str(next->str))
		{
			ft_dprintf(2,
				"syntax error near unexpected token `%s'\n", curr->str);
			return (1);
		}
		if (ft_strcmp(curr->str, "(") == 0
			&& ft_strcmp(next->str, ")") == 0)
		{
			ft_dprintf(2,
				"syntax error near unexpected token `%s'\n", curr->str);
			return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}
