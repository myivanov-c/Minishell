/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:02 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/20 16:37:45 by mykytaivano      ###   ########.fr       */
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



int	parse_cmd_token(t_token *token, t_cmd *cmd)
{
	char	*str;

	str = token->str;
	if (!str)
		return (-1);
	if (!cmd->cmd_name)
	{
		cmd->cmd_name = ft_strdup(str);
		if (!cmd->cmd_name)
			return (-1);
		if (add_arg(cmd, str) == -1)
			return (-1);
	}
	else
	{
		if (add_arg(cmd, str) == -1)
			return (-1);
	}
	return (0);
}

int	add_arg(t_cmd *cmd, char *new_str)
{
	char	**new_args;
	int		count;
	int		i;

	count = 0;
	if (cmd->cmd_args)
		while (cmd->cmd_args[count])
			count++;
	new_args = malloc(sizeof(char *) * (count + 2));
	if (!new_args)
		return (-1);
	i = 0;
	while (i < count)
	{
		new_args[i] = cmd->cmd_args[i];
		i++;
	}
	new_args[i] = ft_strdup(new_str);
	if (!new_args[i])
		return (free(new_args), -1);
	new_args[i + 1] = NULL;
	free(cmd->cmd_args);
	cmd->cmd_args = new_args;
	return (0);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd_name = NULL;
	cmd->cmd_args = NULL;
	cmd->cmd_options = NULL;
	cmd->redirs = NULL;
	return (cmd);
}


t_cmd	*parse_simple_cmd(t_list *tokens)
{
	t_cmd		*cmd;
	t_token		*token;

	cmd = init_cmd();
	if (!cmd)
		return (NULL);
	while (tokens)
	{
		token = (t_token *)tokens->content;
		if (!token || !token->str)
			return (free_one_cmd(cmd), NULL);
		if (is_redirection_token(token->str))
		{
			if (parse_cmd_redir(&tokens, cmd) == -1)
				return (free_one_cmd(cmd), NULL);
		}
		else if (parse_cmd_token(token, cmd) == -1)
			return (free_one_cmd(cmd), NULL);
		tokens = tokens->next;
	}
	return (cmd);
}
