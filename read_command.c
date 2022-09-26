/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:45:28 by aomman            #+#    #+#             */
/*   Updated: 2022/09/08 23:37:31 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_var *var)
{
	add_to_history (var);
	var->s_cmd = ft_split (var->cmd, ' ');
	if (check_builtins(var) == 0)
		n_exec(var);
}

void	ft_cmd(t_var *var)
{
	while (1)
	{
		var->cmd = readline("minishell$ ");
		if (!var->cmd)
		{
			ft_putstr_fd("exit\n", 1);
			exit (1);
		}
		ft_exec (var);
		free (var->cmd);
	}
}
