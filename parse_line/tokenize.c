/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:47:19 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:06:53 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

static int	get_len_token_control(char const *line);
static int	get_len_token(char const *line);
int			ft_iscontrol(char c);

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
			len = get_len_token_control(line);
		else
			len = get_len_token(line);
		if ((len <= 0)
			|| (ft_lstadd_back(&tokens, ft_lstnew(new_token(line, len))) == -1)
			|| (fill_token_flags(ft_lstlast(tokens)->content) == -1))
			return (ft_lstclear(tokens, free_token), NULL);
		line += len;
		while (ft_isspace(*line))
			line++;
	}
	return (tokens);
}

static int	get_len_token_control(char const *line)
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
