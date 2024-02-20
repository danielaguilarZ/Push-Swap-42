/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:07 by daguilar          #+#    #+#             */
/*   Updated: 2024/02/20 19:39:24 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	ft_create_stack_a(&a, argv + 1);
	if (ft_stack_sorted(a) == false)
	{
		if (ft_stack_size(a) == 2)
			ft_sa(&a, true);
		else if (ft_stack_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_all(&a, &b);
	}
	// ft_print_stacks(a, b);
	ft_free_stack(&a);
}
