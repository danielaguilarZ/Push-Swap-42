/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:29 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:46:55 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap Operation

void	ft_swap(t_stack **stack)
{
	int		temp;
	t_stack	*first;
	t_stack	*second;

	first = NULL;
	second = NULL;
	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
	}
	temp = first->nb;
	first->nb = second->nb;
	second->nb = temp;
}

void	ft_sa(t_stack **A, bool print)
{
	ft_swap(A);
	if (print == true)
		ft_printf("sa\n");
}

void	ft_sb(t_stack **B, bool print)
{
	ft_swap(B);
	if (print == true)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **A, t_stack **B, bool print)
{
	ft_swap(A);
	ft_swap(B);
	if (print == true)
		ft_printf("ss\n");
}
