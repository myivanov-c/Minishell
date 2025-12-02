/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:45:54 by causilva          #+#    #+#             */
/*   Updated: 2025/11/29 18:42:47 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"

static int	replace_param(t_token *token, int i, t_vars *vars);
static char	*get_param_name(char *str);
static int	insert_param(t_token *old_token, t_token *token2, int i, int j);
static char	*ft_getenv(char **envp, char *name);

t_list	*get_expanded_env(t_token *token, t_vars *vars)
{
	t_list	*list;
	t_token	*token_dup;
	int		i;
	int		temp;

	token_dup = dup_token(token);
	if (!token_dup)
		return (NULL);
	i = 0;
	while (token_dup->str[i])
	{
		if ((token_dup->str[i] == '$') && (token_dup->quoted[i] != '\''))
		{
			temp = replace_param(token_dup, i, vars);
			if (temp == -1)
				return (NULL);
			i += temp;
		}
		else
			i++;
	}
	list = split_token(token_dup);
	free_token(token_dup);
	return (list);
}

static int	replace_param(t_token *token, int i, t_vars *vars)
{
	char	*param_name;
	char	*param_result;
	t_token	*param;
	int		temp;

	param_name = get_param_name(&token->str[i]);
	if (!param_name || !(*param_name))
		return (free(param_name), -1);
	if (ft_strcmp(param_name, "$") == 0)
		return (free(param_name), 1);
	if (ft_strcmp(param_name, "$?") == 0)
		param_result = ft_itoa(vars->last_exit_status);
	else
		param_result = ft_getenv(vars->envp, &param_name[1]);
	if (!param_result)
		param_result = "";
	param = new_token(param_result, -1);
	if ((special_fill_token_flags(param, token->quoted[i]) == -1)
		|| (insert_param(token, param, i, ft_strlen(param_name)) == -1))
		return (free(param_name), free_token(param), -1);
	temp = ft_strlen(param->str);
	return (free(param_name), free_token(param), temp);
}

static char	*get_param_name(char *str)
{
	int	len;

	if (!str || (*str != '$') || ft_isdigit(str[1]))
		return (NULL);
	len = 1;
	if (str[len] == '?')
		len++;
	else
		while (ft_isalnum(str[len]) || (str[len] == '_'))
			len++;
	return (ft_substr(str, 0, len));
}

static int	insert_param(t_token *old_token, t_token *param, int i, int j)
{
	t_token	*token;
	int		old_token_len;
	int		param_len;

	old_token_len = ft_strlen(old_token->str);
	param_len = ft_strlen(param->str);
	token = new_token("", old_token_len + param_len - j);
	if (!token)
		return (-1);
	ft_memmove(token->str, old_token->str, i);
	ft_memmove(token->quoted, old_token->quoted, i);
	ft_memmove(&token->str[i], param->str, param_len);
	ft_memmove(&token->quoted[i], param->quoted, param_len);
	ft_memmove(&token->str[i + param_len], &old_token->str[i + j],
		old_token_len - i - j);
	ft_memmove(&token->quoted[i + param_len], &old_token->quoted[i + j],
		old_token_len - i - j);
	free(old_token->str);
	free(old_token->quoted);
	old_token->str = token->str;
	old_token->quoted = token->quoted;
	free(token);
	return (0);
}

static char	*ft_getenv(char **envp, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && name[j]
			&& envp[i][j] == name[j]
			&& envp[i][j] != '=')
			j++;
		if (envp[i][j] == '=' && name[j] == '\0')
			return (&envp[i][j + 1]);
		i++;
	}
	return (NULL);
}
