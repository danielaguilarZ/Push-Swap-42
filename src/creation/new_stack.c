/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:39 by daguilar          #+#    #+#             */
/*   Updated: 2024/04/15 20:10:20 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_assign_indexes(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*comp;

	cur = *stack;
	while (cur != NULL)
	{
		comp = *stack;
		while (comp != NULL)
		{
			if (cur->nb <= comp->nb)
				comp = comp->next;
			else if (cur->nb > comp->nb)
			{
				cur->index += 1;
				comp = comp->next;
			}
		}
		cur = cur->next;
	}
}

static void	ft_add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	node->index = 1;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_stack_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_create_stack_a(t_stack **A, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_e_syntax(argv[i]))
			ft_free_errors(A);
		n = ft_atoi_ps(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free_errors(A);
		if (ft_e_duplicated(*A, (int)n))
			ft_free_errors(A);
		ft_add_node(A, (int)n);
		i++;
	}
	ft_assign_indexes(A);
}
