/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:10:27 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/30 17:02:08 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

void		memory_cleanup(t_vars vars);

int	is_numeric_str(const char *s)
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

static int	exit_numeric_error(char *args, t_vars *vars)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(args, 2);
	ft_putendl_fd(": numeric argument required", 2);
	io_cleanup(*vars);
	memory_cleanup(*vars);
	exit(2);
	return (2);
}

static int	exit_too_many_args(int *last_status)
{
	ft_putendl_fd("minishell: exit: too many arguments", 2);
	*last_status = 1;
	return (1);
}

int	builtin_exit(char **argv, t_vars *vars)
{
	long long		value;
	unsigned char	code;

	ft_putendl_fd("exit", 2);
	if (!argv[1])
		code = (unsigned char)(vars->last_exit_status);
	else if (!is_numeric_str(argv[1]))
		return (exit_numeric_error(argv[1], vars));
	else if (argv[2])
		return (exit_too_many_args(&vars->last_exit_status));
	else
	{
		value = ft_atoll_exit(argv[1]);
		code = (unsigned char)value;
	}
	io_cleanup(*vars);
	memory_cleanup(*vars);
	exit(code);
	return (0);
}
