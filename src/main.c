/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/07/12 02:47:29 by mamir            ###   ########.fr       */
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

// int find_smallest(t_list *stack)
// {
//     int smallest_value;
    
//     smallest_value = stack->value;
//     while (stack != NULL)
//     {
//         if (stack->value < smallest_value)
//             smallest_value = stack->value;
//         stack = stack->next;
//     }
//     return smallest_value;
// }
// int	find_second_smallest(t_list *stack)
// {
// 	int smallest_value;
// 	int second_smallest_value;
	
// 	smallest_value = find_smallest(stack);
// 	second_smallest_value = INT_MAX;
// 	while (stack != NULL)
// 	{
// 		if (stack->value > smallest_value && stack->value < second_smallest_value)
// 			second_smallest_value = stack->value;
// 		stack = stack->next;
// 	}
// 	return second_smallest_value;
// }

void sort_stack(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) <= 1)
        return;

    int pivot = (*stack_a)->value;
    int size = ft_lstsize(*stack_a);
    int smaller_elements = 0;

    // Partition the stack based on the pivot
    int i = 0;
    while (i < size)
    {
        if ((*stack_a)->value < pivot)
        {
            pb(stack_a, stack_b);
            smaller_elements++;
        }
        else
        {
            ra(stack_a);
        }
        i++;
    }

    // Recursively sort the smaller elements
    if (smaller_elements > 1)
    {
        int size_b = ft_lstsize(*stack_b);
        while (size_b > 0)
        {
            pa(stack_a, stack_b);
            size_b--;
        }
        sort_stack(stack_a, stack_b);
    }

    // Move the sorted smaller elements back to stack_a
    while (smaller_elements > 0)
    {
        pb(stack_a, stack_b);
        smaller_elements--;
    }

    // Move the larger elements to stack_b
    int larger_elements = size - ft_lstsize(*stack_a);
    while (larger_elements > 0)
    {
        pb(stack_a, stack_b);
        larger_elements--;
    }

    // Recursively sort the larger elements
    if (ft_lstsize(*stack_b) > 1)
    {
        sort_stack(stack_b, stack_a);
        // Move the sorted larger elements back to stack_a
        while (ft_lstsize(*stack_b) > 0)
        {
            pa(stack_a, stack_b);
        }
    }

    // Move the smaller elements back to stack_a
    while (ft_lstsize(*stack_b) > 0)
    {
        pa(stack_a, stack_b);
    }
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
		else if (ft_lstsize(stack_a) == 5)
			sort_stack(&stack_a, &stack_b);
	}
	t_list *tmp = stack_a;
	printf("-----------\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
