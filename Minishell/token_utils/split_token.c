/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:16:57 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:49:58 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	here_add_token(t_list **list, t_token *ref, int i, int len);

t_list	*split_token(t_token *token)
{
	t_list	*list;
	int		len;
	int		i;

	if (!token)
		return (NULL);
	list = NULL;
	i = 0;
	while (ft_isspace(token->str[i]) && !token->quoted[i])
		i++;
	while (token->str[i])
	{
		len = 0;
		while (token->str[i + len]
			&& (!ft_isspace(token->str[i + len]) || token->quoted[i + len]))
			len++;
		if (here_add_token(&list, token, i, len) == -1)
			return (ft_lstclear(&list, free_token), NULL);
		i += len;
		while (ft_isspace(token->str[i]) && !token->quoted[i])
			i++;
	}
	return (list);
}

static int	here_add_token(t_list **list, t_token *ref, int i, int len)
{
	char	*tmp;
	t_token	*token;

	tmp = ft_substr(ref->str, i, len);
	if (!tmp)
		return (-1);
	token = new_token(tmp, -1);
	free(tmp);
	if (!token
		|| special_fill_token_flags(token, ref->quoted[i]) == -1
		|| ft_lstadd_back(list, ft_lstnew(token)) == -1)
		return (free_token(token), (-1));
	ft_memcpy(token->quoted, &ref->quoted[i], len);
	token->quoted[len] = 0;
	token->control = ref->control;
	return (0);
}
