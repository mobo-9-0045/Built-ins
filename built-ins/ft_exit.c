/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:00:59 by aomman            #+#    #+#             */
/*   Updated: 2022/08/27 19:01:00 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_alpha(t_var *var)
{
	var->i = 1;
	while (var->s_cmd[var->i])
	{
		var->j = 0;
		while (var->s_cmd[var->i][var->j])
		{
			if (ft_isalpha(var->s_cmd[var->i][var->j]) == 1)
			{
				ft_putstr_fd("bash: exit: ", 1);
				ft_putstr_fd(var->s_cmd[var->i], 1);
				ft_putstr_fd(": Numeric argumrnts required\n", 1);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (1);
}

void	ft_free(t_var *var)
{
	var->i = 0;
	while (var->s_cmd[var->i])
		free (var->s_cmd[var->i++]);
	free (var->s_cmd);
	var->s_cmd = NULL;
}

int	n_ft_exit(t_var *var)
{
	var->ex_cod = ft_atoi(var->s_cmd[1]);
	if (ft_strcmp(var->s_cmd[1], "9223372036854775808") >= 0)
	{
		ft_putstr_fd("bash: exit: ", 1);
		ft_putstr_fd(var->s_cmd[1], 1);
		ft_putstr_fd(": Numeric argumrnts required\n", 1);
		ft_free (var);
		return (1);
	}
	printf("%d\n", var->ex_cod);
	return (0);
}

void	ft_exit(t_var *var)
{
	if (check_alpha(var) == 0)
	{
		ft_free (var);
		return ;
	}
	if (var->i > 2)
	{
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("bash: exit: too many arguments\n", 1);
		ft_free (var);
		return ;
	}
	if (!var->s_cmd[1])
	{
		free (var->s_cmd[0]);
		exit (0);
	}
	else
	{
		if (n_ft_exit(var) == 1)
			return ;
		else
			exit(var->ex_cod);
	}
	ft_free (var);
}
