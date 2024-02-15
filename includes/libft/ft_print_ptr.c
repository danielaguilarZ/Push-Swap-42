/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:06:45 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:27:50 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

/////////////////////////////////////////////////////////////////////////////

static char	*ft_put_ptr(uintptr_t num)
{
	char	*ptr;
	char	*str;
	int		len;

	len = ft_ptr_len(num);
	ptr = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ptr[num % 16];
		num /= 16;
	}
	return (str);
}

/////////////////////////////////////////////////////////////////////////////

int	ft_print_ptr(uintptr_t ptr)
{
	char	*ptr_str;

	if (ptr == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	ptr_str = ft_put_ptr(ptr);
	ft_putstr(ptr_str);
	free(ptr_str);
	return (ft_ptr_len(ptr) + 2);
}
