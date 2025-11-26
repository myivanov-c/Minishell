/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:10:27 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:13:43 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_numeric_str(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoll_exit(const char *s)
{
	int			i;
	int			sign;
	long long	res;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	exit_numeric_error(char *args, int in_child)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(args, 2);
	ft_putendl_fd(": numeric argument required", 2);
	if (in_child)
		exit(255);
	//clean_and_exit(255);
	return (255);
}

static int	exit_too_many_args(int *last_status)
{
	ft_putendl_fd("minishell: exit: too many arguments", 2);
	*last_status = 1;
	return (1);
}

int	builtin_exit(t_cmd *cmd, int *last_status, int in_child)
{
	char			**args;
	long long		value;
	unsigned char	code;

	args = cmd->cmd_args;
	ft_putendl_fd("exit", 2);
	if (!args[1])
		code = (unsigned char)(*last_status);
	else if (!is_numeric_str(args[1]))
		return (exit_numeric_error(args[1], in_child));
	else if (args[2])
		return (exit_too_many_args(last_status));
	else
	{
		value = ft_atoll_exit(args[1]);
		code = (unsigned char)value;
	}
	if (in_child)
		exit(code);
	//clean_and_exit(code);
	return (0);
}


