/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:06:22 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/01 11:12:31 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_sizewords(char const *s, int c)
{
	size_t	word_len;
	char	*found;

	word_len = 0;
	found = ft_strchr(s, c);
	if (!found)
		word_len = ft_strlen(s);
	else
		word_len = found - s;
	return (word_len);
}

static char	*ft_words(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_sizewords(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	leak(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;

	str = (char **)malloc(sizeof(char *) * (ft_nwords(s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			str[i] = ft_words(s, c);
			if (!str[i])
				return (leak(str, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	str[i] = 0;
	return (str);
}
