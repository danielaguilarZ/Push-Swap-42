/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:03:44 by daguilar          #+#    #+#             */
/*   Updated: 2023/09/30 17:33:53 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strstart(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(s2, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_strend(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(s2, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

static char	*ft_blank(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_strstart(s1, set);
	end = ft_strend(s1, set);
	if (start >= end)
		return (ft_blank());
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
