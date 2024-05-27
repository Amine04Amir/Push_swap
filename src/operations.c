/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:55 by mamir             #+#    #+#             */
/*   Updated: 2024/05/27 10:59:08 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "sb\n", 3);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ft_lstlast(*stack_a);
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list *last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ft_lstlast(*stack_b);
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}