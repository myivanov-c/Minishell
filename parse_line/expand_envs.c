/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:52:21 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:16:24 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

static int	expand_envs_token(t_token *token);
static int	replace_env(t_token *token, int i);

int	expand_envs(t_cmdtree *cmdtree)
{
	t_list *token_node;
	t_list *temp;

	if (!cmdtree)
		return (-1);
	if (cmdtree->type == 4)
	{
		token_node = cmdtree->tokens;
		while (token_node)
		{
			temp = token_node->next;
			if (expand_envs_token(token_node->content) == -1)
				return (-1);
			token_node = temp;
		}
	}
	if (cmdtree->child1)
		if (expand_envs(cmdtree->child1) == -1)
			return (-1);
	if (cmdtree->child2)
		if (expand_envs(cmdtree->child2) == -1)
			return (-1);
	return (0);
}

static int	expand_envs_token(t_token *token)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (token->str[i])
	{
		if ((token->str[i] == '$') && (token->quote_flags[i] != '\''))
		{
			j = get_env_len(&token->str[i]);
			if (j == -1)
				return (-1);
			temp = replace_env(token, i, j);
			if (temp == -1)
				return (-1);
			i += temp;
		}
		else
			i++;
	}
	return (split_token(token));
}

static int	replace_env(t_token *token, int i)
{
	
}
static int	replace_env(t_token *token, int i)
{
	int		j;
	char	*envname;
	t_token	*env_token;
	int		env_len;

	if (!token->str || (*token->str != '$') || ft_isdigit(token->str[1]))
		return (-1);
	j = 1;
	if (token->str[i + j] == '?')
		j++;
	else
		while (ft_isalnum(token->str[i + j]) || (token->str[i + j] == '_'))
			j++;
	envname = ft_substr(token->str, i, j);
	if (!envname || !(*envname))
		return (free(envname), -1);
	if (ft_strcmp(envname, "$") == 0)
		return (free(envname), 1);


	env_token = new_token(getenv(envname), -1);
	special_fill_token_flags(env_token);
	token_splice(token, env_token, i, j - 1);


	env_len = ft_strlen(env_token->str);
	free(envname);
	free_token(env_token);
	return (env_len);
}
