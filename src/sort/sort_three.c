/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:07 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:40 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_three(t_stack **A)
{
	t_stack	*max_node;

	max_node = ft_stack_max(*A);
	if (max_node == *A)
		ft_ra(A, true);
	else if ((*A)->next == max_node)
		ft_rra(A, true);
	if ((*A)->nb > (*A)->next->nb)
		ft_sa(A, true);
}
