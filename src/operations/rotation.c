/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:24 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:31 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotation Operation

void	ft_rotation(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_stack_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ft_ra(t_stack **A, bool print)
{
	ft_rotation(A);
	if (print == true)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **B, bool print)
{
	ft_rotation(B);
	if (print == true)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **A, t_stack **B, bool print)
{
	ft_rotation(A);
	ft_rotation(B);
	if (print == true)
		ft_printf("rr\n");
}

void	ft_rr_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		ft_rr(A, B, true);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
}
