/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:55 by mamir             #+#    #+#             */
/*   Updated: 2024/06/08 21:51:48 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	last = *stack;
	before_last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}
void ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}