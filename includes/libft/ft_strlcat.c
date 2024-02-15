/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:30:08 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/01 11:03:56 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstsize;
	size_t	srcsize;
	size_t	result;

	result = 0;
	i = 0;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (size == 0)
		return (size + srcsize);
	if (size > dstsize)
		result = srcsize + dstsize;
	else
		result = srcsize + size;
	while (src[i] && (dstsize < size - 1))
	{
		dst[dstsize] = src[i];
		dstsize++;
		i++;
	}
	dst[dstsize] = '\0';
	return (result);
}
