/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/07/11 04:14:42 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **stack_a)
{
	int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && a < c)
		sa(stack_a);
	else if (a > c && b < c)
		ra(stack_a);
	else if (a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c)
		rra(stack_a);
}

int is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void find_smallest_and_second_smallest(t_list *stack)
{
	int smallest_value = stack->value;
	int second_smallest_value = INT_MAX;
	t_list *tmp = stack;
	
	while (tmp != NULL)
	{
		if (tmp->value < smallest_value)
			smallest_value = tmp->value;
		tmp = tmp->next;
	}
	while (stack != NULL)
	{
		if (stack->value > smallest_value && stack->value < second_smallest_value)
			second_smallest_value = stack->value;
		stack = stack->next;
	}
	printf("smallest: %d\n", smallest_value);
	printf("second smallest: %d\n", second_smallest_value);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list *stack_b;
	int *array;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac < 2)
		ft_error("no args\n");
	parse_args(ac , av, &stack_a);
	array = malloc(sizeof(int) * (ft_lstsize(stack_a) + 1));
	if (is_sorted(stack_a))
		ft_error("sorted!");
	else
	{
		if (ft_lstsize(stack_a) == 2 && stack_a->value > stack_a->next->value)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);	
	}
	find_smallest_and_second_smallest(stack_a);
	t_list *tmp = stack_a;
	printf("-----------\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
