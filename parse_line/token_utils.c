/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:02 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:33:17 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
#include "parse_line.h"

t_token	*new_token(char const *line, int len)
{
	t_token	*token;
	int		size;

	if (!line)
		return (NULL);
	if (len >= 0)
		size = len + 1;
	else
		size = ft_strlen(line) + 1;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = malloc(size * sizeof(char));
	token->quote_flags = malloc(size * sizeof(char));
	if (!token->str || !token->quote_flags)
		return (free_token(token), NULL);
	ft_strlcpy(token->str, line, size);
	ft_bzero(token->quote_flags, size);
	return (token);	
}

t_token	*dup_token(t_token *old_token)
{
	t_token	*token;
	int		len;

	if (!old_token || !old_token->str || !old_token->quote_flags)
		return (NULL);
	len = ft_strlen(old_token->str);
	token = new_token(old_token->str, len);
	if (!token)
		return (NULL);
	ft_memcpy(token->quote_flags, old_token->quote_flags, (len + 1));
	return (token);	
}
int	fill_token_flags(t_token *token)
{
	int		i;
	int		inside_quotes;

	if (!token)
		return (-1);
	i = 0;
	inside_quotes = 0;
	while (token->str[i])
	{
		token->quote_flags[i] = inside_quotes;
		if ((inside_quotes == 0)
			&& (token->str[i] == '\'' || token->str[i] == '\"'))
			inside_quotes = token->str[i];
		else if (inside_quotes == token->str[i])
		{
			inside_quotes = 0;
			token->quote_flags[i] = 0;
		}
		i++;
	}
	if (inside_quotes)
		return (-1);
	return (0);
}

void	free_token(void *token)
{
	t_token *tok;

	tok = (t_token *)token;
	if (tok)
	{
		free(tok->str);
		free(tok->quote_flags);
		free(tok);
	}
}
