#include "../includes/push_swap.h"

int ft_min(t_stack *stack)
{
    int min;

    min = stack->nbr;
    while (stack)
    {
        if (min > stack->nbr)
            min = stack->nbr;
        stack = stack->next;
    }
    return (min);
}

int ft_max(t_stack *stack)
{
    int max;

    max = stack->nbr;
    while (stack)
    {
        if (max < stack->nbr)
            max = stack->nbr;
        stack = stack->next;
    }
    return (max);
}

int find_index(t_stack *stack, int nbr)
{
    int i;

    i = 0;
    while(stack->nbr != nbr)
    {
        i++;
        stack = stack->next;
    }
    stack->index = 0;
    return (i);
}

void sort_three(t_stack **stk_a)
{
    if (ft_min(*stk_a) == (*stk_a)->nbr)    
    {
        rra(stk_a);
        sa(stk_a);
    }
    else if (ft_max(*stk_a) == (*stk_a)->nbr)
    {
        ra(stk_a);
        if(!is_sorted(*stk_a))
            sa(stk_a);
    }
    else
    {
        if (find_index(*stk_a, ft_max(*stk_a)))
            rra(stk_a);
        else
            sa(stk_a);
    }
}

void ft_sort(t_stack **stk_a)
{
    t_stack *stk_b;
    // int     i;

    stk_b = NULL;
    if (ft_lstsize(*stk_a) == 2)
        sa(stk_a);
    else
    {
        sort_three(stk_a);
    }
}
