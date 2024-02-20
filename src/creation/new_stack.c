/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:39 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/20 18:28:00 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_assign_indexes(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		smaller_than;

	smaller_than = 0;
	current = *stack;
	while (current)
	{
		temp = *stack;
		smaller_than = 0;
		while (temp)
		{
			if (temp->nb < current->nb)
				smaller_than++;
			temp = temp->next;
		}
		current->index = smaller_than;
		current = current->next;
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

void	ft_print_stacks(t_stack *A, t_stack *B)
{
	ft_printf("\n");
	if (A == NULL)
		ft_printf("Stack A: \n");
	else
	{
		ft_printf("Stack A: \n");
		while (A != NULL)
		{
			ft_printf("Valor: %i | Índice: %i | Posición: %i\n", A->nb,
				A->index, A->pos);
			A = A->next;
		}
	}
	ft_printf("\n");
	if (B == NULL)
		ft_printf("Stack B: \n");
	else
	{
		ft_printf("Stack B: \n");
		while (B != NULL)
		{
			ft_printf("Valor: %i | Índice: %i | Posición: %i | Posición Objetivo: %i\n", B->nb, B->index, B->pos,
				B->target_pos);
			B = B->next;
		}
	}
}
