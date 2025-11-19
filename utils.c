/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:33 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/19 12:52:29 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    if (s1 == s2)
        return (0);
    if (!s1)
        return (-1);
    if (!s2)
        return (1);
    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

void	free_one_cmd(t_cmd *cmd)
{
	t_list *node;
	t_list *next;

	if (!cmd)
		return ;
	free(cmd->cmd_name);
	free_str_array(cmd->cmd_args);
	free_str_array(cmd->cmd_options);
	node = cmd->redirs;
	while (node)
	{
		t_redirs *r = (t_redirs *)node->content;
		if (r)
		{
			free(r->file);
			free(r);
		}
		next = node->next;
		free(node);
		node = next;
	}
	free(cmd);
}

void	free_cmd_array(t_cmd *cmd_array)
{
	int	i;

	if (!cmd_array)
		return ;
	i = 0;
	while (cmd_array[i].cmd_full_str)
	{
		free(cmd_array[i].cmd_full_str);
		free(cmd_array[i].cmd_name);
		free_str_array(cmd_array[i].cmd_options);
		free_str_array(cmd_array[i].cmd_args);
		//free(cmd_array[i].input_name);
		//free(cmd_array[i].input_delimiter);
		//free(cmd_array[i].output_name);
		i++;
	}
	free (cmd_array);
}

void	free_str_array(char **str_array)
{
	int	i;

	if (!str_array)
		return ;
	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
}
