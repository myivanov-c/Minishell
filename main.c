/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:38:41 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:47:12 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (ft_strcmp(tk->str, "&&") == 0
		|| ft_strcmp(tk->str, "||") == 0
		|| ft_strcmp(tk->str, "|") == 0);
}



void	append_token_list(t_list **dst, t_list *src)
{
	t_list	*tmp;

	if (!dst || !src)
		return ;
	if (!*dst)
	{
		*dst = src;
		return ;
	}
	tmp = *dst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = src;
}

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
					return (1);
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


int	is_line_complete(t_list *tokens)
{
	t_list	*last;
	t_token	*tk;

	if (!tokens)
		return (1);
	last = tokens;
	while (last->next)
		last = last->next;
	tk = (t_token *)last->content;
	if (!tk || !tk->str)
		return (1);
	if (is_operator_str(tk->str) || ft_strcmp(tk->str, "(") == 0)
		return (0);
	if (!parens_are_fully_closed(tokens))
		return (0);
	return (1);
}




int     has_invalid_operator_sequence(t_list *tokens)
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
			return (1);
		if (ft_strcmp(curr->str, "(") == 0
			&& ft_strcmp(next->str, ")") == 0)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

int	has_invalid_paren_sequences(t_list *tokens)
{
	t_list	*node;
	t_token	*prev;
	t_token	*curr;
	t_token	*next;

	node = tokens;
	prev = NULL;
	while (node)
	{
		curr = (t_token *)node->content;
		if (!curr || !curr->str)
		{
			prev = curr;
			node = node->next;
			continue ;
		}
		if (ft_strcmp(curr->str, "(") == 0)
		{
			if (prev && prev->str
				&& !is_operator_str(prev->str)
				&& ft_strcmp(prev->str, "(") != 0)
				return (1);
			if (node->next)
			{
				next = (t_token *)node->next->content;
				if (next && next->str && is_operator_str(next->str))
					return (1);
			}
		}
		if (ft_strcmp(curr->str, ")") == 0 && node->next)
		{
			next = (t_token *)node->next->content;
			if (next && next->str
				&& !is_operator_str(next->str)
				&& ft_strcmp(next->str, ")") != 0)
				return (1);
		}
		prev = curr;
		node = node->next;
	}
	return (0);
}

int	has_fatal_syntax_error(t_list *tokens)
{
	if (has_unmatched_closing_paren(tokens))
		return (1);
	if (has_invalid_operator_sequence(tokens))
		return (1);
	if (has_invalid_paren_sequences(tokens))
		return (1);
	return (0);
}


t_list	*read_and_accumulate_tokens(void)
{
	char	*line;
	t_list	*all_tokens;
	t_list	*tokens;

	all_tokens = NULL;
	line = readline(">> ");
	while (line)
	{
		if (!*line && !all_tokens)
			return (free(line), NULL);
		add_history(line);
		tokens = tokenize(line);
		free(line);
		if (line_starts_with_op(tokens))
			return (printf("syntax error near unexpected token '%s'\n",
				((t_token *)tokens->content)->str), ft_lstclear(&tokens, free_token), ft_lstclear(&all_tokens, free_token), NULL);
		append_token_list(&all_tokens, tokens);
		if (has_fatal_syntax_error(all_tokens))
			return (printf("syntax error\n"), ft_lstclear(&all_tokens,free_token), NULL);
		if (is_line_complete(all_tokens))
			break;
		line = readline(">> ");
	}
	return (all_tokens);
}


int	main(void)
{
	t_list	*all_tokens;
    t_cmd	*cmd_array;

	while (1)
	{
		all_tokens = read_and_accumulate_tokens();
		if (!all_tokens)
			continue;
        cmd_array = parse_line(all_tokens);
        if (cmd_array)
        {
            // run_commands(cmd_array);
            // free_cmd_array(cmd_array);
        }
	}
	rl_clear_history();
	return (0);
}