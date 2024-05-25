#include "../includes/push_swap.h"

void ft_sa(t_list **stack_a)
{
    t_list *tmp;
    
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}