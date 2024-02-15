/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:31:14 by daguilar          #+#    #+#             */
/*   Updated: 2023/09/30 17:32:06 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	i = 0;
	strdst = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	if (!strdst && !strsrc)
		return (0);
	if (strdst > strsrc)
	{
		while (len--)
			strdst[len] = strsrc[len];
	}
	else
	{
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	return (strdst);
}
