/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:52:26 by aomman            #+#    #+#             */
/*   Updated: 2022/08/16 18:42:12 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	g_alloc(char **env)
{
	g_var.i = 0;
	while (env[g_var.i])
		g_var.i++;
	g_var.env = (char **)malloc(sizeof(char *) * (g_var.i + 1));
	g_var.i = 0;
	while (env[g_var.i])
	{
		g_var.env[g_var.i] = ft_strdup(env[g_var.i]);
		g_var.i++;
	}
	g_var.env[g_var.i] = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	argv = NULL;
	argc = 1;
	g_alloc(env);
	ft_cmd(var);
	free (var);
	return (0);
}
