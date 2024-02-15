/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:16:10 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/01 09:44:46 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	i = 0;
	strdst = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	if (!strdst && !strsrc)
		return (0);
	while (i < n)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	return (strdst);
}
