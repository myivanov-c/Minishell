/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:02 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/19 12:52:13 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirection_token(char *str)
{
	return (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, ">") || !ft_strcmp(str, ">>"));
}

int	get_redir_type(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (REDIR_IN);
	if (!ft_strcmp(str, "<<"))
		return (REDIR_HEREDOC);
	if (!ft_strcmp(str, ">"))
		return (REDIR_OUT);
	if (!ft_strcmp(str, ">>"))
		return (REDIR_APPEND);
	return (-1);
}

int	parse_cmd_redir(t_list **tokens, t_cmd *cmd)
{
	t_redirs	*redir;
	t_token		*tok_op;
	t_token		*tok_file;
	t_list		*node;

	if (!(*tokens)->next)
		return (printf("syntax error: expected file after redirection\n"), -1);
	tok_op = (t_token *)(*tokens)->content;
	*tokens = (*tokens)->next;
	tok_file = (t_token *)(*tokens)->content;
	redir = malloc(sizeof(t_redirs));
	if (!redir)
		return (-1);
	redir->type = get_redir_type(tok_op->str);
	redir->file = ft_strdup(tok_file->str);
	if (!redir->file)
		return (free(redir), -1);
	node = ft_lstnew(redir);
	if (!node)
		return (free(redir->file), free (redir), -1);
	ft_lstadd_back(&cmd->redirs, node);
	return (0);
}
