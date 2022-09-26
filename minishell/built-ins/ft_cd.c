/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:43:36 by aomman            #+#    #+#             */
/*   Updated: 2022/09/07 18:46:12 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(t_var *var)
{
	char	*path;
	int		i;

	i = 1;
	if (!var->s_cmd[i])
		path = ft_strdup(getenv("HOME"));
	else
		path = ft_strdup(var->s_cmd[i]);
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", var->s_cmd[i]);
		return ;
	}
	free (path);
	i = 0;
	while (var->s_cmd[i])
		free (var->s_cmd[i++]);
	free (var->s_cmd);
}
