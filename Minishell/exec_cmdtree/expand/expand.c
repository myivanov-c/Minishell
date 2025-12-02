/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:06:33 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:41:48 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"

static int	expand_env(t_list **token_ptr, t_vars *vars);
static int	expand_wild(t_list **token_ptr);
static void	replace(t_list **token_ptr, t_list *expanded_lst, int is_wild);
static void	remove_quotes_token(t_token *token);

int	expand(t_list **tokens_ptr, t_vars *vars)
{
	t_token	*token;

	if (expand_env(tokens_ptr, vars) == -1)
		return (-1);
	while (*tokens_ptr)
	{
		token = (*tokens_ptr)->content;
		remove_quotes_token(token);
		if (expand_wild(tokens_ptr) == -1)
			return (-1);
		tokens_ptr = &(*tokens_ptr)->next;
	}
	return (0);
}

static int	expand_env(t_list **token_ptr, t_vars *vars)
{
	t_token	*token;
	t_list	*expanded_lst;
	t_list	**temp;

	while (*token_ptr)
	{
		token = (*token_ptr)->content;
		if (token->control == 6)
		{
			token_ptr = &(*token_ptr)->next->next;
			continue ;
		}
		expanded_lst = get_expanded_env(token, vars);
		if (token->control == 10 && (!expanded_lst || expanded_lst->next))
		{
			printf("minishel: %s: ambiguous redirect\n", token->str);
			return (ft_lstclear(&expanded_lst, free_token), -1);
		}
		temp = token_ptr;
		if (expanded_lst)
			temp = &(ft_lstlast(expanded_lst)->next);
		replace(token_ptr, expanded_lst, 0);
		token_ptr = temp;
	}
	return (0);
}

static int	expand_wild(t_list **token_ptr)
{
	t_token	*token;
	t_list	*expanded_lst;
	t_list	**temp;

	while (*token_ptr)
	{
		token = (*token_ptr)->content;
		if (token->control == 6)
		{
			token_ptr = &(*token_ptr)->next->next;
			continue ;
		}
		expanded_lst = get_expanded_wild(token);
		if (token->control == 10 && (expanded_lst && expanded_lst->next))
		{
			printf("minishel: %s: ambiguous redirect\n", token->str);
			return (ft_lstclear(&expanded_lst, free_token), -1);
		}
		temp = &(*token_ptr)->next;
		if (expanded_lst)
			temp = &(ft_lstlast(expanded_lst)->next);
		replace(token_ptr, expanded_lst, 1);
		token_ptr = temp;
	}
	return (0);
}

static void	replace(t_list **token_ptr, t_list *expanded_lst, int is_wild)
{
	t_list	*temp;

	if (!expanded_lst && is_wild)
		return ;
	temp = *token_ptr;
	if (expanded_lst)
	{
		*token_ptr = expanded_lst;
		ft_lstlast(expanded_lst)->next = temp->next;
	}
	else
		*token_ptr = temp->next;
	ft_lstdelone(temp, free_token);
}

static void	remove_quotes_token(t_token *token)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(token->str);
	while (token->str[i])
	{
		if (((token->str[i] == '\'') || (token->str[i] == '\"'))
			&& (token->quoted[i] == 0))
		{
			ft_memmove(&token->str[i], &token->str[i + 1], len - i);
			ft_memmove(&token->quoted[i], &token->quoted[i + 1], len - i);
			len--;
		}
		else
			i++;
	}
}
