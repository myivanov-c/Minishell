/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:47:19 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/19 12:55:41 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

static int	get_len_token_control(char const *line);
static int	get_len_token(char const *line);
int			ft_iscontrol(char c);

void    print_list(t_list *list)
{
    while (list)
    {
        t_token *tok = (t_token *)list->content;
        printf("List: %s\n", tok->str);
        list = list->next;
    }
}

int	extract_token_len(const char *line)
{
	if (ft_iscontrol(*line))
		return (get_len_token_control(line));
	return (get_len_token(line));
}

int	push_token(t_list **tokens, const char *line, int len)
{
	t_token	*tok;
	t_list	*node;

	tok = new_token(line, len);
	if (!tok)
		return (-1);
	if (fill_token_flags(tok) == -1)
	{
		free_token(tok);
		return (-1);
	}
	node = ft_lstnew(tok);
	if (!node)
	{
		free_token(tok);
		return (-1);
	}
	if (ft_lstadd_back(tokens, node) == -1)
	{
		free_token(tok);
		free(node);
		return (-1);
	}
	return (0);
}


t_list	*tokenize(const char *line)
{
	t_list	*tokens;
	int		len;

	if (!line)
		return (NULL);
	while (ft_isspace(*line))
		line++;
	tokens = NULL;
	while (*line)
	{
		len = extract_token_len(line);
		if (len <= 0)
			return (ft_lstclear(&tokens, free_token), NULL);
		if (push_token(&tokens, line, len) == -1)
			return (ft_lstclear(&tokens, free_token), NULL);
		line = line + len;
		while (ft_isspace(*line))
			line++;
	}
	return (tokens);
}

static int	get_len_token_control(const char *line)
{
	int			i;
	int			len;
	static char	*valid_controls[9] = {
		"||", "|", "<<", "<", ">>", ">", "&&", "(", ")"};
	
	i = 0;
	while (i < 9)
	{
		len = ft_strlen(valid_controls[i]);
		if (ft_strncmp(line, valid_controls[i], len) == 0)
			return (len);
		i++;
	}
	return (-1);
}

static int	get_len_token(char const *line)
{
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
	return (i);
}

int     ft_iscontrol(char c)
{
	return ((c == '&')
		|| (c == '(')
		|| (c == ')')
		|| (c == ';')
		|| (c == '<')
		|| (c == '>')
		|| (c == '\\')
		|| (c == '|'));
}
