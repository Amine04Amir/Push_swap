/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/06/06 22:27:01 by mamir            ###   ########.fr       */
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

void parse_args(int ac, char **av, t_list **stack_a)
{
	int i;
	int nums;
	char **string;

	if (ac == 2)
	{
		i = 0;
		string = ft_split(av[1], ' ');
		while (string[i])
		{
			nums = ft_atoi(string[i]);
			ft_lstadd_back(stack_a, ft_lstnew(nums));
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			nums = ft_atoi(av[i]);
			ft_lstadd_back(stack_a, ft_lstnew(nums));
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac < 2)
		ft_error();
	parse_args(ac , av, &stack_a);
	ft_sort_three(&stack_a);
	// t_list *tmp = stack_a;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->value);
	// 	tmp = tmp->next;
	// }
}
