/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:45:09 by aomman            #+#    #+#             */
/*   Updated: 2022/09/07 21:08:57 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_var *var)
{
	var->i = 0;
	while (g_var.env[var->i])
	{
		if (ft_char(g_var.env[var->i], '=') != 0)
		{
			ft_putstr_fd(g_var.env[var->i], 1);
			write (1, "\n", 1);
		}
		var->i++;
	}
	var->i = 0;
	while (var->s_cmd[var->i])
		free (var->s_cmd[var->i++]);
	free (var->s_cmd);
}
