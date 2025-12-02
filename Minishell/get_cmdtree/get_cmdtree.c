/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:38:41 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 11:17:20 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_line.h"
#include "../minishell.h"

int	is_redirection_token(char *str);

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

int	add_heredocs(int **heredocs, int heredoc)
{
	int	*new_heredocs;
	int	len;
	int	i;

	len = 0;
	while ((*heredocs)[len] != -1)
		len++;
	new_heredocs = malloc((len + 2) * sizeof(int));
	if (!new_heredocs)
		return (-1);
	i = -1;
	while (++i < len)
		new_heredocs[i] = (*heredocs)[i];
	new_heredocs[i] = heredoc;
	new_heredocs[i + 1] = -1;
	free(*heredocs);
	*heredocs = new_heredocs;
	return (0);
}

int	parse_heredocs(t_list *tokens, t_vars *vars)
{
	t_token	*tk;
	int		res;

	while (tokens)
	{
		tk = tokens->content;
		if (tk->control == 6)
		{
			res = handle_heredoc(tokens);
			if (!res)
				return (-1);
			tokens = tokens->next;
			tk = tokens->content;
			tk->fd_heredoc = res;
			if (add_heredocs(&vars->heredocs, res) == -1)
				return (-1);
		}
		tokens = tokens->next;
	}
	return (0);
}

t_list	*read_and_accumulate_tokens(t_vars *vars)
{
	t_list	*tokens;
	char	*line;

	line = readline(">> ");
	tokens = tokenize_and_append(line);
	if (!tokens)
	{
		ctrld_intercepted(line, &tokens);
		return (free(line), NULL);
	}
	if (!is_line_complete(tokens))
	{
		add_history(line);
		return (
			ft_dprintf(2,
				"minishell: syntax error near unexpected token `newline'\n"),
			NULL);
	}
	if (process_syntax_checks(&tokens, line) == -1)
		return (free(line), NULL);
	if (parse_heredocs(tokens, vars) == -1)
		return (free(line), NULL);
	return (add_hyst_return(&line, tokens));
}

t_cmdtree	*get_cmdtree(t_vars *vars)
{
	t_list	*all_tokens;

	all_tokens = read_and_accumulate_tokens(vars);
	if (!all_tokens)
	{
		vars->last_exit_status = 2;
		return (NULL);
	}
	vars->cmdtree = parse_line(all_tokens);
	return (vars->cmdtree);
}
