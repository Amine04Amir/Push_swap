#include "../../includes/push_swap.h"

void sort_three(t_stack **stack)
{
    t_stack *biggest_node;

    biggest_node = find_max(*stack);
    if (biggest_node == *stack)
        ra(stack);
    else if ((*stack)->next == biggest_node)
        rra(stack);
    if ((*stack)->nbr > (*stack)->next->nbr)
        sa(stack);
}
