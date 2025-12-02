/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 12:08:42 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

int	has_fatal_syntax_error(t_list *tokens)
{
	if (has_unmatched_closing_paren(tokens))
		return (1);
	if (has_invalid_operator_sequence(tokens))
		return (1);
	if (has_invalid_paren_sequences(tokens))
		return (1);
	return (0);
}

int	process_syntax_checks(t_list **all, char *line)
{
	int		rstat;

	if (has_fatal_syntax_error(*all))
	{
		add_history(line);
		ft_lstclear(all, free_token);
		return (-1);
	}
	rstat = has_invalid_redirection_sequences(*all);
	if (rstat)
	{
		if (rstat == 2)
			ft_dprintf(2,
				"minishell: syntax error near unexpected token `newline'\n");
		else
			ft_dprintf(2, "minishell: syntax error: double redirection\n");
		add_history(line);
		ft_lstclear(all, free_token);
		return (-1);
	}
	return (0);
}
