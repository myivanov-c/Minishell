/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wilds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:52:59 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/19 15:04:37 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

int	expand_wilds_tokenlst(t_list **tokens);

int	expand_wilds(t_cmdtree *cmdtree)
{
	if (!cmdtree)
		return (-1);
	if (cmdtree->type == 4)
		return (expand_wilds_tokenlst(&cmdtree->tokens));
	if (cmdtree->child1)
		if (expand_wilds(cmdtree->child1) == -1)
			return (-1);
	if (cmdtree->child2)
		if (expand_wilds(cmdtree->child2) == -1)
			return (-1);
	return (0);
}

int     has_unquoted_star(t_token *tok)
{
    int     i;

    i = 0;
    if (!tok || !tok->str || !tok->quote_flags)
        return (0);
    while (tok->str[i])
    {
        if (tok->str[i] == '*' && tok->quote_flags[i] == 0)
            return (1);
        i++;
    }
    return (0);
}

t_list  *make_token_from_str(char const *str)
{
    t_token  *tok;

    if (!str)
        return (NULL);
    tok = new_token(str, -1);
    if (!tok)
        return (NULL);
    return (ft_lstnew(tok));
}

int     insert_matches_after_node(t_list *node, char **matches)
{
	int		i;
	t_list	*new;
	t_list	*next;

	if (!node || !matches)
		return (-1);
	next = node->next;
	i = 0;
	while (matches[i])
	{
		new = make_token_from_str(matches[i]);
		if (!new)
			return (-1);
		node->next = new;
		node = new;
		i++;
	}
	node->next = next;
	return (0);
}

void    remove_node_and_free(t_list **head, t_list *prev, t_list *curr)
{
    if (prev)
        prev->next = curr->next;
    else
        *head = curr->next;
    ft_lstdelone(curr, free_token);
}

int	process_wilds_token(t_list **tokens, t_list **prev, t_list **curr)
{
	t_token	*tok;
	char	**matches;

	tok = (t_token *)(*curr)->content;
	if (!has_unquoted_star(tok))
		return (0);
	matches = total_filtered_outcomes_multi(tok->str);
	if (matches && matches[0])
	{
		if (insert_matches_after_node(*curr, matches) == -1)
			return (-1);
		free_array_split(matches);
		remove_node_and_free(tokens, *prev, *curr);
		if (*prev)
			*curr = (*prev)->next;
		else
			*curr = *tokens;
		return (1);
	}
	free_array_split(matches);
	return (0);
}

int	expand_wilds_tokenlst(t_list **tokens)
{
	t_list	*curr;
	t_list	*prev;
	int		res;

	if (!tokens || !*tokens)
		return (0);
	curr = *tokens;
	prev = NULL;
	while (curr)
	{
		res = process_wilds_token(tokens, &prev, &curr);
		if (res == -1)
			return (-1);
		if (res == 1)
			continue;
		prev = curr;
		curr = curr->next;
	}
	return (0);
}