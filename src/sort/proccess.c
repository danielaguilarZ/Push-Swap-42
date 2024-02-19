/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:37 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:36 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_ra_rra(t_stack **A, t_stack *cheapest)
{
	while (cheapest->cost_a != 0)
	{
		if (cheapest->cost_a > 0)
		{
			ft_ra(A, true);
			cheapest->cost_a--;
		}
		else
		{
			ft_rra(A, true);
			cheapest->cost_a++;
		}
	}
}

static void	ft_rb_rrb(t_stack **B, t_stack *cheapest)
{
	while (cheapest->cost_b != 0)
	{
		if (cheapest->cost_b > 0)
		{
			ft_rb(B, true);
			cheapest->cost_b--;
		}
		else
		{
			ft_rrb(B, true);
			cheapest->cost_b++;
		}
	}
}

static void	ft_find_target_positions(t_stack **A, t_stack **B)
{
	t_stack	*current_b;
	t_stack	*current_a;
	t_stack	*target;

	current_b = *B;
	while (current_b)
	{
		current_a = *A;
		target = NULL;
		while (current_a)
		{
			if (current_a->index > current_b->index && (!target
					|| current_a->index < target->index))
				target = current_a;
			current_a = current_a->next;
		}
		if (target)
			current_b->target_pos = target->pos;
		else
			ft_smallest_index_to_pos(A, current_b);
		current_b = current_b->next;
	}
}

void	ft_cost_calculation(t_stack **A, t_stack **B)
{
	t_stack	*current_b;

	current_b = *B;
	while (current_b)
	{
		ft_find_target_positions(A, B);
		if (current_b->target_pos <= ft_stack_size(*A) / 2)
			current_b->cost_a = current_b->target_pos;
		else
			current_b->cost_a = (ft_stack_size(*A) - current_b->target_pos) *
				-1;
		if (current_b->pos <= ft_stack_size(*B) / 2)
			current_b->cost_b = current_b->pos;
		else
			current_b->cost_b = (ft_stack_size(*B) - current_b->pos) * -1;
		current_b = current_b->next;
	}
}

void	ft_make_sequence(t_stack **A, t_stack **B, t_stack *cheapest)
{
	if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		ft_rr_both(A, B, cheapest);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		ft_rrr_both(A, B, cheapest);
	ft_ra_rra(A, cheapest);
	ft_rb_rrb(B, cheapest);
	ft_pa(B, A, true);
}