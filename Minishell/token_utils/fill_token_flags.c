/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:45:58 by causilva          #+#    #+#             */
/*   Updated: 2025/11/19 15:56:39 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		token->quoted[i] = inside_quotes;
		if ((inside_quotes == 0)
			&& (token->str[i] == '\'' || token->str[i] == '\"'))
			inside_quotes = token->str[i];
		else if (inside_quotes == token->str[i])
		{
			inside_quotes = 0;
			token->quoted[i] = 0;
		}
		i++;
	}
	if (inside_quotes)
		return (-1);
	return (0);
}

int	special_fill_token_flags(t_token *token, char quoted)
{
	int		i;

	if (!token)
		return (-1);
	i = -1;
	if (quoted)
		while (token->str[++i])
			token->quoted[i] = quoted;
	else
	{
		while (token->str[++i])
		{
			if ((token->str[i] == '\'') || (token->str[i] == '\"'))
				token->quoted[i] = '\'';
			else
				token->quoted[i] = 0;
		}
	}
	return (0);
}
