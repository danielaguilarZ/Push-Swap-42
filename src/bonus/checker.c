/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:47:18 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:14 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_operation_checker(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 4) == 0)
		ft_sa(&a, false);
	if (ft_strncmp(operation, "sb\n", 4) == 0)
		ft_sb(&b, false);
	if (ft_strncmp(operation, "ss\n", 4) == 0)
		ft_ss(&a, &b, false);
	if (ft_strncmp(operation, "ra\n", 4) == 0)
		ft_ra(&a, false);
	if (ft_strncmp(operation, "rb\n", 4) == 0)
		ft_rb(&b, false);
	if (ft_strncmp(operation, "rr\n", 4) == 0)
		ft_rr(&a, &b, false);
	if (ft_strncmp(operation, "rra\n", 5) == 0)
		ft_rra(&a, false);
	if (ft_strncmp(operation, "rrb\n", 5) == 0)
		ft_rrb(&b, false);
	if (ft_strncmp(operation, "rrr\n", 5) == 0)
		ft_rrr(&a, &b, false);
	if (ft_strncmp(operation, "pa\n", 4) == 0)
		ft_pa(&a, &b, false);
	if (ft_strncmp(operation, "pb\n", 4) == 0)
		ft_pb(&a, &b, false);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*operation;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	ft_create_stack_a(&a, argv + 1);
	operation = get_next_line(0);
	while (operation != NULL)
	{
		if (ft_strncmp(operation, "Error\n", 7) == 0)
			ft_printf("Error");
		ft_operation_checker(a, b, operation);
		operation = get_next_line(0);
	}
	if (ft_stack_sorted(a) == true)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&a);
}
