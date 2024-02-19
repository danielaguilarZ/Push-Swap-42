/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:37 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:38:42 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_position(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

t_stack	*ft_smallest_index(t_stack **A)
{
	t_stack	*current_a;
	t_stack	*smallest_index;

	current_a = *A;
	smallest_index = *A;
	while (current_a)
	{
		if (current_a->index < smallest_index->index)
			smallest_index = current_a;
		current_a = current_a->next;
	}
	return (smallest_index);
}

void	ft_smallest_index_to_pos(t_stack **A, t_stack *current_b)
{
	t_stack	*current_a;
	t_stack	*smallest_index;

	current_a = *A;
	smallest_index = *A;
	while (current_a)
	{
		if (current_a->index < smallest_index->index)
			smallest_index = current_a;
		current_a = current_a->next;
	}
	current_b->target_pos = smallest_index->pos;
}
