/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:58:39 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/01 10:50:31 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	sing;
	int	result;
	int	i;

	result = 0;
	sing = 1;
	i = 0;
	while (nptr[i] && (nptr[i] == '\f' || nptr[i] == '\t' || nptr[i] == ' '
			|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
		{
			sing = -1;
		}
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i++] - '0';
	}
	result *= sing;
	return (result);
}
