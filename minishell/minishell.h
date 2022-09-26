/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:49:38 by aomman            #+#    #+#             */
/*   Updated: 2022/09/18 18:13:34 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define   MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_var
{
	int		argc;
	int		i;
	int		j;
	int		ex_cod;
	char	*key_env;
	char	**s_env;
	char	*oldpwd;
	char	*key_cmd;
	char	**env;
	char	**path;
	char	*pwd_path;
	char	*cmd;
	char	*f_path;
	char	**s_cmd;
}	t_var;

t_var	g_var;

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, int buff);
int		check_equal(t_var *var);
int		check_digit(t_var *var);
int		check_builtins(t_var *var);
int		ft_char(char *str, char c);
int		ft_isalpha(char c);
int		ft_isalpha_e_u(char c);
int		ft_atoi(const char *str);
int		ft_error(t_var *var);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *str, int fd);
void	ft_cmd(t_var *var);
void	ft_command(t_var *var);
void	ft_pwd(t_var *var);
void	n_exec(t_var *var);
void	ft_unset(t_var *var);
void	add_to_history(t_var *var);
void	ft_cd(t_var *var);
void	ft_echo(t_var *var);
void	ft_env(t_var *var);
void	ft_exit(t_var *var);
void	ft_export(t_var *var);
void	normale_export(t_var *var);
void	ft_normale_export2(t_var *var);
#endif
