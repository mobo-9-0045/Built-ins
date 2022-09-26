/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exece_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:21:37 by aomman            #+#    #+#             */
/*   Updated: 2022/08/24 09:58:15 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	add_to_history(t_var *var)
{
	if (var->s_cmd)
		add_history (var->cmd);
}

void	ft_command(t_var *var)
{
	int	i;

	i = 0;
	if (ft_strcmp (var->s_cmd[i], "pwd") == 0)
		ft_pwd(var);
	else if (ft_strcmp (var->s_cmd[i], "echo") == 0)
		ft_echo(var);
	else if (ft_strcmp (var->s_cmd[i], "cd") == 0)
		ft_cd(var);
	else if (ft_strcmp (var->s_cmd[i], "export") == 0)
		ft_export(var);
	else if (ft_strcmp (var->s_cmd[i], "unset") == 0)
		ft_unset(var);
	else if (ft_strcmp (var->s_cmd[i], "env") == 0)
		ft_env(var);
	else if (ft_strcmp (var->s_cmd[i], "exit") == 0)
		ft_exit(var);
}

int	check_builtins(t_var *var)
{
	int	i;

	i = 0;
	if (ft_strcmp (var->s_cmd[i], "pwd") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "echo") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "cd") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "export") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "unset") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "env") == 0)
		return (0);
	if (ft_strcmp (var->s_cmd[i], "exit") == 0)
		return (0);
	return (1);
}

void	n_exec(t_var *var)
{
	ft_command(var);
}
