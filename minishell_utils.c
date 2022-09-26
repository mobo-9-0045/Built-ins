/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:31:33 by aomman            #+#    #+#             */
/*   Updated: 2022/08/16 18:38:38 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minishell.h"

int	ft_strncmp(const char *s1, const char *s2, int buff)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < buff)
	{
		if ((str1[i] != str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	diff = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
	{
		diff = s1[i] - s2[i];
		return (diff);
	}
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j) + 1);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '/';
	i++;
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;	

	i = 0;
	while (str[i] != '\0')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (i >= 0)
	{
		s[i] = str[i];
		i--;
	}
	return (s);
}
