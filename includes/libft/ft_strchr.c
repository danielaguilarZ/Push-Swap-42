/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:44:08 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/02 13:28:23 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	str = (char *)s;
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
