#include "../includes/push_swap.h"

void ft_sa(t_list **stack_a)
{
    t_list *tmp;
    
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "sa\n", 3);
}

void ft_sb(t_list **stack_b)
{
    t_list *tmp;
    
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "sb\n", 3);
}

void ft_ra(t_list **stack_a)
{
    t_list *last;

    last = ft_lstlast(*stack_a);
    last->next = *stack_a;
    *stack_a = (*stack_a)->next;
    last->next->next = NULL;
    write(1, "ra\n", 3);
}

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


