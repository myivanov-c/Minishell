/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:45:00 by causilva          #+#    #+#             */
/*   Updated: 2025/12/02 11:24:34 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	tokenize_control(t_list **tokens_ptr, char const *line);
static int	tokenize_str(t_list **tokens_ptr, char const *line);
static int	check_redirect_names(t_list *tokens);
static int	ft_iscontrol(char c);

t_list	*tokenize(char const *line)
{
	t_list	*tokens;
	int		len;

	if (!line)
		return (NULL);
	tokens = NULL;
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		if (ft_iscontrol(*line))
			len = tokenize_control(&tokens, line);
		else
			len = tokenize_str(&tokens, line);
		if (len <= 0)
			return (ft_lstclear(&tokens, free_token), NULL);
		line += len;
		while (ft_isspace(*line))
			line++;
	}
	len = tokenize_control(&tokens, line);
	if (check_redirect_names(tokens) == -1)
		return (ft_lstclear(&tokens, free_token), NULL);
	return (tokens);
}

static int	tokenize_control(t_list **tokens_ptr, char const *line)
{
	t_token		*token;
	int			i;
	int			len;
	static char	*valid_controls[9] = {
		"(", ")", "&&", "||", "|", "<<", "<", ">>", ">"};

	i = 0;
	while (i < 9)
	{
		len = ft_strlen(valid_controls[i]);
		if (ft_strncmp(line, valid_controls[i], len) == 0)
			break ;
		i++;
	}
	if (i == 9)
		return (-1);
	token = new_token(line, len);
	if ((!token)
		|| (fill_token_flags(token) == -1)
		|| (ft_lstadd_back(tokens_ptr, ft_lstnew(token)) == -1))
		return (free_token(token), -1);
	token->control = i + 1;
	return (len);
}

static int	tokenize_str(t_list **tokens_ptr, char const *line)
{
	t_token	*token;
	int		i;
	int		inside_quotes;

	i = 0;
	inside_quotes = 0;
	while (line[i]
		&& (inside_quotes || (!ft_isspace(line[i]) && !ft_iscontrol(line[i]))))
	{
		if ((inside_quotes == 0)
			&& (line[i] == '\'' || line[i] == '\"'))
			inside_quotes = line[i];
		else if (inside_quotes == line[i])
			inside_quotes = 0;
		i++;
	}
	if (inside_quotes)
		return (-1);
	token = new_token(line, i);
	if ((!token)
		|| (fill_token_flags(token) == -1)
		|| (ft_lstadd_back(tokens_ptr, ft_lstnew(token)) == -1))
		return (free_token(token), -1);
	return (i);
}

static int	check_redirect_names(t_list *node)
{
	t_token	*token;

	while (node)
	{
		token = node->content;
		if (token->control == 6 || token->control == 7
			|| token->control == 8 || token->control == 9)
		{
			node = node->next;
			if (!node)
				return (0);
			token = node->content;
			if (token->control != 0)
				return (0);
			token->control = 10;
		}
		node = node->next;
	}
	return (0);
}

static int	ft_iscontrol(char c)
{
	return ((c == '(')
		|| (c == ')')
		|| (c == '&')
		|| (c == '|')
		|| (c == '<')
		|| (c == '>')
		|| (c == ';')
		|| (c == '\\'));
}
