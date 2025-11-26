/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:54:41 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:14:04 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_n_flag(char *str)
{
    int     i;

    if (!str || str[0] != '-' || str[1] != 'n')
        return (0);
    i = 2;
    while (str[i])
    {
        if (str[i] != 'n')
            return (0);
        i++;
    }
    return (1);
}
int builtin_echo(t_cmd *cmd)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    while (cmd->cmd_args[i] && is_n_flag(cmd->cmd_args[i]))
    {
        newline = 0;
        i++;
    }
    while (cmd->cmd_args[i])
    {
        write(1, cmd->cmd_args[i], ft_strlen(cmd->cmd_args[i]));
        if (cmd->cmd_args[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (newline)
        write(1, "\n", 1);
    return (0);
}
