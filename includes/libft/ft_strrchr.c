/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:24:21 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/01 09:49:58 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return (&str[i]);
		}
		i--;
	}
	return (NULL);
}
