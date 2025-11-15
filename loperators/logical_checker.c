/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:26:37 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/28 17:54:58 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"

int     parentheses_are_balanced(char **res)
{
    int     i;
    int     open;

    i = 0;
    open = 0;
    while (res[i])
    {
        if (ft_strcmp(res[i], "(") == 0)
            open++;
        else if (ft_strcmp(res[i], ")") == 0)
        {
            if (open == 0)
                return (0);
            open--;
        }
        i++;
    }
    if (open == 0)
        return (1);
    return (0);
}

int     check_for_logical_operators(char **res)
{
    int     i;
    int     valid;

    i = 0;
    valid = 0;
    if (has_operator(res, 0))
    {
        if (is_operator(res[0]))
                return (0);
    }
    while (res[i] != NULL)
    {
        if (has_operator(res, i))
        {
            if (is_operator(res[i]))
                valid++;
            else
                return (0);
        }
        i++;
    }
    return (valid);
}

int     check_adjacent_operators(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (is_operator(res[i]))
		{
			if (res[i + 1] && is_operator(res[i + 1]))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int     count_commands(char **res)
{
    int     count;
    int     i;

    i = 0;
    count = 1;
    while (res[i])
    {
        if (is_operator(res[i]))
            count++;
        i++;
    }
    return (count);
}

t_split_org	*init_struct_array(char **res, int *num_cmds)
{
	t_split_org	*s_org;

	*num_cmds = count_commands(res);
	s_org = malloc(sizeof(t_split_org) * (*num_cmds + 1));
	if (!s_org)
		return (NULL);
	ft_bzero(s_org, sizeof(t_split_org) * (*num_cmds + 1));
	return (s_org);
}

int	fill_command_struct(t_split_org *s_org, char **res, int *i, int k)
{
	while (res[*i] && ft_strcmp(res[*i], "(") == 0)
		s_org[k].open_p = res[(*i)++];
	if (!res[*i] || ft_strcmp(res[*i], ")") == 0 || is_operator(res[*i]))
		return (0);
	s_org[k].cmd = res[(*i)++];
	if (res[*i] && !is_operator(res[*i])
		&& ft_strcmp(res[*i], "(") != 0
		&& ft_strcmp(res[*i], ")") != 0)
		s_org[k].arg = res[(*i)++];
	if (res[*i] && ft_strcmp(res[*i], ")") == 0)
		s_org[k].close_p = res[(*i)++];
	if (res[*i] && is_operator(res[*i]))
		s_org[k].op = res[(*i)++];
	return (1);
}

t_split_org	*parse_tokens_to_struct(char **res)
{
	int			i;
	int			k;
	int			num_cmds;
	t_split_org	*s_org;

	i = 0;
	k = 0;
	s_org = init_struct_array(res, &num_cmds);
	if (!s_org)
		return (NULL);
	while (res[i])
	{
		if (!fill_command_struct(s_org, res, &i, k))
		{
			free(s_org);
			return (NULL);
		}
		k++;
	}
	s_org[k].cmd = NULL;
	s_org[k].arg = NULL;
	s_org[k].op = NULL;
	s_org[k].open_p = NULL;
	s_org[k].close_p = NULL;
	return (s_org);
}

int	invalid_token(char *token)
{
	if (!token)
		return (1);
	if (is_operator(token))
		return (1);
	if ((token[0] == '(' && token[1] == '\0')
		|| (token[0] == ')' && token[1] == '\0'))
		return (1);
	return (0);
}
int	invalid_operator_context(t_split_org *s, int i)
{
	if (!s[i + 1].cmd || !s[i + 1].arg)
		return (1);
	if (is_operator(s[i + 1].cmd) || is_operator(s[i + 1].arg))
		return (1);
	if ((s[i + 1].arg[0] == '(' && s[i + 1].arg[1] == '\0')
		|| (s[i + 1].arg[0] == ')' && s[i + 1].arg[1] == '\0'))
		return (1);
	return (0);
}

int	check_struct_syntax(t_split_org *s)
{
	int	i;

	i = 0;
	while (s[i].cmd != NULL)
	{
		if (invalid_token(s[i].cmd) || invalid_token(s[i].arg))
			return (0);
		if (s[i].op && invalid_operator_context(s, i))
			return (0);
		i++;
	}
	return (1);
}


int	check_if_logical_mode(char *str)
{
	char		**res;
	t_split_org	*s_org;

	res = smart_split(str);
	if (!res)
		return (0);
	if (check_for_logical_operators(res) == 0
		|| last_token_is_operator(res)
		|| parentheses_are_balanced(res) == 0
		|| check_adjacent_operators(res) == 0)
		return (free_array_split(res), 0);
	s_org = parse_tokens_to_struct(res);
	if (!s_org)
		return (free_array_split(res), 0);
	if (!check_struct_syntax(s_org))
	{
		free(s_org);
		free_array_split(res);
		return (0);
	}
	free(s_org);
	free_array_split(res);
	return (1);
}


int     main(int argc, char **argv)
{
    int     status;
    char    **res;
    int     i;
    
    if (argc < 2)
        return (0);
    res = smart_split(argv[1]);
    status = check_if_logical_mode(argv[1]);
    i = 0;
    while (res[i] != NULL)
    {
        printf("In pos %d, I have: %s\n", i, res[i]);
        i++;
    }
    free_array_split(res);
    printf("Status check: %d\n", status);
    return (0);
}