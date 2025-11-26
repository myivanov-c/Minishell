/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:20:05 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:14:16 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     count_args(char  **args)
{
    int  i;

    i = 0;
    if (!args)
        return (0);
    while (args[i])
        i++;
    return (i);
}

int     builtin_cd(t_cmd *cmd)
{
    int     argc;
    char    *path;

    argc = count_args(cmd->cmd_args);
    if (argc == 1)
    {
        write (2, "cd: missing argument\n", 22);
        return (1);
    }
    if (argc > 2)
    {
        write (2, "cd: too many arguments\n", 24);
        return (1);
    }
    path = cmd->cmd_args[1];
    if (chdir(path) == -1)
    {
        write (2, "cd: ", 4);
        write (2, path, ft_strlen(path));
        write (2, ": ", 2);
        perror("");
        return (1);
    }
    return (0);
}

