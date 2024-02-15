/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:04 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:49:45 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nwords(char *s, char c)
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

static int	ft_sizewords(char *s, char c)
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

static char	*ft_words(char *s, char c)
{
	char		*str;
	int			i;
	static int	cursor = 0;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_sizewords(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[cursor] == c)
		++cursor;
	while (s[cursor] && s[cursor] != c)
	{
		str[i] = s[cursor];
		i++;
		cursor++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split_ps(char *s, char c)
{
	int		i;
	int		nwords;
	char	**str;

	nwords = ft_nwords(s, c);
	str = (char **)malloc(sizeof(char *) * (ft_nwords(s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (nwords-- >= 0)
	{
		if (i == 0)
		{
			str[i] = malloc(sizeof(char));
			if (!str)
				return (NULL);
			str[i++][0] = '\0';
			continue ;
		}
		str[i++] = ft_words(s, c);
	}
	str[i] = 0;
	return (str);
}
