/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/06/07 02:33:30 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		ft_sa(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		ft_ra(stack_a);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		ft_rra(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac < 2)
		ft_error("no args\n");
	parse_args(ac , av, &stack_a);
	ft_sort_three(&stack_a);
	// t_list *tmp = stack_a;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->value);
	// 	tmp = tmp->next;
	// }
}
