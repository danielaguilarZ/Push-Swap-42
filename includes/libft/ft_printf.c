/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:28:33 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:48:16 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////

int	ft_print_c(char c)
{
	(write(1, &c, 1));
	return (1);
}
/////////////////////////////////////////////////////////////////////////////

static int	ft_whattype(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_c(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, uintptr_t)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_uputnbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex_min(va_arg(args, int)));
	if (c == 'X')
		return (ft_print_hex_max(va_arg(args, int)));
	return (0);
}

/////////////////////////////////////////////////////////////////////////////

static int	ft_percernt_or_type(char c, va_list args)
{
	int	res;

	res = 0;
	if (c != '%')
	{
		res = ft_whattype(c, args);
		return (res);
	}
	else
	{
		ft_putchar('%');
		return (1);
	}
}

/////////////////////////////////////////////////////////////////////////////

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_percernt_or_type(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
