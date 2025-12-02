/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_tokenlst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:25:01 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:50:38 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_argv_tokenlst(t_list *tokens)
{
	char	**argv;
	int		i;

	argv = malloc((count_tokens(tokens) + 1) * sizeof(char *));
	if (!argv)
		return (NULL);
	i = 0;
	while (tokens)
	{
		if (!((t_token *)tokens->content)->control)
		{
			argv[i] = ((t_token *)tokens->content)->str;
			i++;
		}
		tokens = tokens->next;
	}
	argv[i] = NULL;
	return (argv);
}
