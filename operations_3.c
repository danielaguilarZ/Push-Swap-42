/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:20 by daguilar          #+#    #+#             */
/*   Updated: 2024/01/24 13:40:54 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotation

void	ft_rerverse_rotation(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_to_last;

	if (*stack && (*stack)->next)
	{
		prev_to_last = NULL;
		last = *stack;
		while (last->next != NULL)
		{
			prev_to_last = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		prev_to_last->next = NULL;
	}
}

void	ft_rra(t_stack **A, bool print)
{
	ft_rerverse_rotation(A);
	if (print == true)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **B, bool print)
{
	ft_rerverse_rotation(B);
	if (print == true)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **A, t_stack **B, bool print)
{
	ft_rerverse_rotation(A);
	ft_rerverse_rotation(B);
	if (print == true)
		ft_printf("rrr\n");
}

// void	ft_rrr_both(t_stack **A, t_stack **B, t_stack *optimal_node)
// {
// 	while (*B != optimal_node->target_node && *A != optimal_node)
// 		ft_rrr(A, B, true);
// 	ft_current_index(*A);
// 	ft_current_index(*B);
// }
