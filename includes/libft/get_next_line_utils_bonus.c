/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:44 by quakk             #+#    #+#             */
/*   Updated: 2024/01/24 13:49:09 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strchr(char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	str = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i] != ch)
	{
		if (str[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (&str[i]);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * gnl_ft_strlen(s1) + gnl_ft_strlen(s2)
			+ 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[gnl_ft_strlen(s1) + gnl_ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_obtain_line(char *savedstr)
{
	int		i;
	char	*str;

	i = 0;
	if (!savedstr)
		return (NULL);
	while (savedstr[i] != '\0' && savedstr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (savedstr[i] && savedstr[i] != '\n')
	{
		str[i] = savedstr[i];
		i++;
	}
	if (savedstr[i] == '\n')
	{
		str[i] = savedstr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_delete_line(char *savedstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!savedstr)
		return (NULL);
	while (savedstr[i] && savedstr[i] != '\n')
		i++;
	if (!savedstr[i])
	{
		free(savedstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * gnl_ft_strlen(savedstr) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (savedstr[i])
		str[j++] = savedstr[i++];
	str[j] = '\0';
	free(savedstr);
	return (str);
}
