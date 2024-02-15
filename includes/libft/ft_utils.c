/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:37:14 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:48:26 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/////////////////////////////////////////////////////////////////////////////

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/////////////////////////////////////////////////////////////////////////////

int	ft_print_str(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		res++;
	}
	return (res);
}

/////////////////////////////////////////////////////////////////////////////

int	ft_putnbr(int num)
{
	long int	nb;
	int			res;

	res = 0;
	nb = num;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		res++;
	}
	if (nb >= 10)
	{
		res += ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		res++;
	}
	return (res);
}

/////////////////////////////////////////////////////////////////////////////

unsigned int	ft_uputnbr(unsigned int num)
{
	int	res;

	res = 0;
	if (num >= 10)
	{
		res += ft_uputnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		res++;
	}
	return (res);
}
