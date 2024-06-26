/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:10 by daguilar          #+#    #+#             */
/*   Updated: 2024/04/12 14:28:51 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// [ OPERATIONS ]

// Push

void				ft_push(t_stack **src, t_stack **dst);
void				ft_pb(t_stack **A, t_stack **B, bool print);
void				ft_pa(t_stack **B, t_stack **A, bool print);

// Swap

void				ft_swap(t_stack **stack);
void				ft_sa(t_stack **A, bool print);
void				ft_sb(t_stack **B, bool print);
void				ft_ss(t_stack **A, t_stack **B, bool print);

// Rotation

void				ft_rotation(t_stack **stack);
void				ft_ra(t_stack **A, bool print);
void				ft_rb(t_stack **B, bool print);
void				ft_rr(t_stack **A, t_stack **B, bool print);
void				ft_rr_both(t_stack **A, t_stack **B, t_stack *cheapest);

// Reverse rotation

void				ft_rerverse_rotation(t_stack **stack);
void				ft_rra(t_stack **A, bool print);
void				ft_rrb(t_stack **B, bool print);
void				ft_rrr(t_stack **A, t_stack **B, bool print);
void				ft_rrr_both(t_stack **A, t_stack **B, t_stack *cheapest);

// Utils

long				ft_atoi_ps(const char *s);
char				**ft_split_ps(char *s, char c);
int					nb_absolute(int nb);

// Stack utils

t_stack				*ft_stack_last(t_stack *stack);
t_stack				*ft_stack_max(t_stack *stack);
int					ft_stack_size(t_stack *stack);
bool				ft_stack_sorted(t_stack *stack);

void				ft_create_stack_a(t_stack **A, char **argv);
void				ft_print_stacks(t_stack *A, t_stack *B);

// Utils

// Nodes

// Errors

int					ft_e_syntax(char *str);
int					ft_e_duplicated(t_stack *A, int n);
void				ft_free_stack(t_stack **stack);
void				ft_free_errors(t_stack **A);

// Sort

void				ft_sort_three(t_stack **A);
void				ft_find_position(t_stack **stack);
void				ft_cost_calculation(t_stack **A, t_stack **B);
void				ft_sort_all(t_stack **A, t_stack **B);
void				ft_rr_both(t_stack **A, t_stack **B, t_stack *cheapest);
void				ft_make_sequence(t_stack **A, t_stack **B,
						t_stack *cheapest);
void				ft_sort_all(t_stack **A, t_stack **B);
void				ft_operation_checker(t_stack **a, t_stack **b,
						char *operation);
t_stack				*ft_smallest_index(t_stack **A);
void				ft_smallest_index_to_pos(t_stack **A, t_stack *current_b);

#endif
