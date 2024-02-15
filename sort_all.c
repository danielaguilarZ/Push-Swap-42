#include "push_swap.h"


// Assign index to the numbers depending on their value.
// EX: [ 9 , 7 , 0 , 2 ]
// Ix: { 4 , 3 , 1 , 2 }

void ft_assign_indexes(t_stack **stack)
{
    t_stack *current;
    t_stack *temp;
    int smaller_than;

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

void ft_find_position(t_stack **stack)
{
    t_stack *current;
    int i;

    i = 0;
    current = *stack;
    while (current)
    {
        current->pos = i;
        i++;
        current = current->next;
    }
}

// Target node

void ft_find_target_positions(t_stack **A, t_stack **B)
{
    t_stack *current_b;
    t_stack *current_a;
    t_stack *smallest_index;
    t_stack *target;
    smallest_index = *A;
    current_b = *B;
    while (current_b)
    {
        current_a = *A;
        target = NULL;
        while (current_a)
        {
            if (current_a->index > current_b->index &&
                (!target || current_a->index < target->index))
                target = current_a;
            current_a = current_a->next;
        }
        if (target)
            current_b->target_pos = target->pos;   
        else
        { 
            current_a = *A;
            while (current_a)
            {
                if (current_a->index < smallest_index->index)
                    smallest_index = current_a;
                current_a = current_a->next;
            }
            current_b->target_pos = smallest_index->pos;
        }
        current_b = current_b->next;
    }
}

// void ft_find_target_positions(t_stack **A, t_stack **B)
// {
//     t_stack *current_b = *B;

//     // Inicializar el índice más pequeño en la pila A
//     t_stack *smallest_index = *A;

//     while (current_b)
//     {
//         t_stack *current_a = *A;
//         t_stack *target = NULL;

//         // Recorrer la pila A para encontrar el objetivo adecuado
//         while (current_a)
//         {
//             if (current_a->index > current_b->index &&
//                 (!target || current_a->index < target->index))
//             {
//                 target = current_a;
//             }
//             // Actualizar el índice más pequeño en la pila A
//             if (current_a->index < smallest_index->index)
//             {
//                 smallest_index = current_a;
//             }
//             current_a = current_a->next;
//         }

//         // Asignar el objetivo o el índice más pequeño si no se encontró ningún objetivo
//         if (target)
//         {
//             current_b->target_pos = target->pos;
//         }
//         else
//         {
//             current_b->target_pos = smallest_index->pos;
//         }

//         current_b = current_b->next;
//     }
// }



void ft_cost_calculation(t_stack **A, t_stack **B)
{
    t_stack *current_b;
    current_b = *B;
    ft_find_target_positions(A, B);
    while (current_b)
    {
        ft_find_target_positions(A, B);
        if (current_b->target_pos <= ft_stack_size(*A) / 2)
            current_b->cost_a = current_b->target_pos;
        else
            current_b->cost_a = (ft_stack_size(*A) - current_b->target_pos) * -1;

        if (current_b->pos <= ft_stack_size(*B) / 2)
            current_b->cost_b = current_b->pos;
        else
            current_b->cost_b = (ft_stack_size(*B) - current_b->pos) * -1;
        current_b = current_b->next;
    }
}

static int nb_absolute(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

t_stack *ft_do_cheapest_move(t_stack **B)
{
	t_stack	*current_b;
	t_stack	*cheapest;

	current_b = *B;
    cheapest = current_b;
	while (current_b)
	{
		if (nb_absolute(current_b->cost_a) + nb_absolute(current_b->cost_b) < nb_absolute(cheapest->cost_a) + nb_absolute(cheapest->cost_b))
			cheapest = current_b;	
		current_b = current_b->next;
	}
    return (cheapest);
}

void ft_rr_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
    while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
    {
        ft_rr(A, B, true);
        cheapest->cost_a--;
        cheapest->cost_b--;
    }
}

void ft_rrr_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
    while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
    {
        ft_rrr(A, B, true);
        cheapest->cost_a++;
        cheapest->cost_b++;
    }
}

void ft_make_sequence(t_stack **A, t_stack **B, t_stack *cheapest)
{
    ft_find_target_positions(A, B);
	if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		ft_rr_both(A, B, cheapest);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		ft_rrr_both(A, B, cheapest);
    while (cheapest->cost_a != 0)
    {
        if (cheapest->cost_a > 0)
        {
            ft_ra(A, true);
            cheapest->cost_a--;
        }
        else
        {
            ft_rra(A , true);
            cheapest->cost_a++;
        }
    }
    while (cheapest->cost_b != 0)
    {
        if (cheapest->cost_b > 0)
        {
            ft_rb(B, true);
            cheapest->cost_b--;
        }
        else
        {
            ft_rrb(B , true);
            cheapest->cost_b++;
        }
    }
	ft_pa(B, A, true);
}


void ft_ra_last(t_stack **A)
{
    t_stack *current_a;
    t_stack *top;
    t_stack *smallest_index;
    int count;
    ft_find_position(A);
    smallest_index = *A;
    top = *A;
    current_a = *A;
    while (current_a)
    {
        if (current_a->index < smallest_index->index)
            smallest_index = current_a;
        current_a = current_a->next;
    }

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

// First we push the half of numbers that are lower than the average index,
// then we push B the rest numbers until the stack size is 3. We sort that 3 numbers then.

void ft_push_b_until_3(t_stack **A, t_stack **B)
{
    int average_index;

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
        ft_pb(A , B, true);
    ft_sort_three(A);
    ft_find_position(A);
    ft_find_position(B);
    ft_cost_calculation(A, B);
}

void ft_sort_all(t_stack **A, t_stack **B)
{
    t_stack *cheapest;
    ft_push_b_until_3(A, B);
    while (*B)
	{
        ft_cost_calculation(A, B);
		cheapest = ft_do_cheapest_move(B);
        ft_make_sequence(A, B, cheapest);
        ft_find_position(A);
        ft_find_position(B);
	}
    if (ft_stack_sorted(*A) == false)
        ft_ra_last(A);
    ft_find_position(A);
}
