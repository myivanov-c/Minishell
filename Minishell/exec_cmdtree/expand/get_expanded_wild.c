/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_wild.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:50:50 by causilva          #+#    #+#             */
/*   Updated: 2025/11/29 18:42:42 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"

int	has_unquoted_star(t_token *tok)
{
	int	i;

	i = 0;
	if (!tok || !tok->str || !tok->quoted)
		return (0);
	while (tok->str[i])
	{
		if (tok->str[i] == '*' && tok->quoted[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

t_list	*make_token_from_str(char const *str, t_token *ref)
{
	t_token	*tok;
	t_list	*node;

	if (!str)
		return (NULL);
	tok = new_token(str, -1);
	if (!tok)
		return (NULL);
	tok->control = ref->control;
	node = ft_lstnew(tok);
	if (!node)
	{
		free_token(tok);
		return (NULL);
	}
	return (node);
}

t_list	*get_expanded_wild(t_token *token)
{
	char	**matches;
	t_list	*list;
	int		i;

	if (!has_unquoted_star(token))
		return (NULL);
	matches = total_filtered_outcomes_multi(token->str);
	if (!matches || !*matches)
		return (free_array_split(matches), NULL);
	i = 0;
	list = make_token_from_str(matches[i], token);
	while (matches[++i])
		ft_lstadd_back(&list, make_token_from_str(matches[i], token));
	free_array_split(matches);
	return (list);
}
