/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_general.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:49 by causilva          #+#    #+#             */
/*   Updated: 2025/11/29 17:52:53 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"

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
	token->quoted = malloc(size * sizeof(char));
	token->control = 0;
	token->fd_heredoc = 0;
	if (!token->str || !token->quoted)
		return (free_token(token), NULL);
	ft_bzero(token->str, size);
	ft_strlcpy(token->str, line, size);
	ft_bzero(token->quoted, size);
	return (token);
}

t_token	*dup_token(t_token *old_token)
{
	t_token	*token;
	int		len;

	if (!old_token || !old_token->str || !old_token->quoted)
		return (NULL);
	len = ft_strlen(old_token->str);
	token = new_token(old_token->str, len);
	if (!token)
		return (NULL);
	ft_memcpy(token->quoted, old_token->quoted, (len + 1));
	token->control = old_token->control;
	token->fd_heredoc = old_token->fd_heredoc;
	return (token);
}

void	free_token(void *ptr)
{
	t_token	*token;

	token = ptr;
	if (token)
	{
		free(token->str);
		free(token->quoted);
		free(token);
	}
}

int	count_tokens(t_list *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		i++;
		tokens = tokens->next;
	}
	return (i);
}
