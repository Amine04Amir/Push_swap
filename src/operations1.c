#include "../includes/push_swap.h"

void ft_rra(t_list **stack_a)
{
    t_list *last = *stack_a;
    t_list *before_last = NULL;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    write(1, "rra\n", 3);
}

void ft_rrb(t_list **stack_b)
{
    t_list *last = *stack_b;
    t_list *before_last = NULL;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 3);
}
