/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:37:49 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/20 19:39:08 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_ra_last(t_stack **A)
{
	t_stack	*top;
	t_stack	*smallest_index;
	int		count;

	top = *A;
	smallest_index = ft_smallest_index(A);
	count = ft_stack_size(*A) - smallest_index->pos;
	if (count >= ft_stack_size(*A) / 2)
	{
		while (smallest_index->pos != top->pos)
		{
			ft_ra(A, true);
			smallest_index->pos--;
		}
	}
	else
	{
		while (count > 0)
		{
			ft_rra(A, true);
			count--;
		}
	}
}

static void	ft_push_b_until_3(t_stack **A, t_stack **B)
{
	int	average_index;

	average_index = 0;
	average_index = ft_stack_size(*A) / 2;
	if (average_index % 2 != 0)
		average_index += 1;
	while (*A && (ft_stack_size(*A) > average_index) && ft_stack_size(*A) > 3)
	{
		if ((*A)->index <= average_index)
			ft_pb(A, B, true);
		else
			ft_ra(A, true);
	}
	while (*A && ft_stack_size(*A) > 3)
		ft_pb(A, B, true);
	ft_sort_three(A);
}

static t_stack	*ft_calc_cheapest_move(t_stack **B)
{
	t_stack	*current_b;
	t_stack	*cheapest;

	current_b = *B;
	cheapest = current_b;
	while (current_b)
	{
		if (nb_absolute(current_b->cost_a)
			+ nb_absolute(current_b->cost_b) < nb_absolute(cheapest->cost_a)
			+ nb_absolute(cheapest->cost_b))
			cheapest = current_b;
		current_b = current_b->next;
	}
	return (cheapest);
}

void	ft_sort_all(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;
	
	ft_push_b_until_3(A, B);
	while (*B)
	{
		ft_cost_calculation(A, B);
		cheapest = ft_calc_cheapest_move(B);
		ft_make_sequence(A, B, cheapest);
		ft_find_position(A);
		ft_find_position(B);
	}
	if (ft_stack_sorted(*A) == false)
		ft_ra_last(A);
}
