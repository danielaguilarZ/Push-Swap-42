/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:32:23 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:24:48 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////

static int	ft_hex_len(unsigned int num)
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

static char	*ft_put_hex_min(unsigned int num)
{
	char	*hex;
	char	*str;
	int		len;

	len = ft_hex_len(num);
	hex = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

/////////////////////////////////////////////////////////////////////////////

static char	*ft_put_hex_max(unsigned int num)
{
	char	*hex;
	char	*str;
	int		len;

	len = ft_hex_len(num);
	hex = "0123456789ABCDEF";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

/////////////////////////////////////////////////////////////////////////////

int	ft_print_hex_min(unsigned int num)
{
	char	*hex_str;

	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		hex_str = ft_put_hex_min(num);
		ft_putstr(hex_str);
		free(hex_str);
		return (ft_hex_len(num));
	}
}

/////////////////////////////////////////////////////////////////////////////

int	ft_print_hex_max(unsigned int num)
{
	char	*hex_str;

	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		hex_str = ft_put_hex_max(num);
		ft_putstr(hex_str);
		free(hex_str);
		return (ft_hex_len(num));
	}
}
