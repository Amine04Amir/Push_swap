/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:46:00 by mamir             #+#    #+#             */
/*   Updated: 2024/05/26 16:57:31 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void ft_pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_a == NULL)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}
