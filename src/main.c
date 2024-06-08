/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/06/08 19:08:36 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort_three(t_list **stack_a)
{
	int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

	if (a > b && b > c)
	{
		ft_sa(stack_a, "sa\n");
		ft_rra(stack_a, "rra\n");
	}
	else if (a > b && a < c)
		ft_sa(stack_a, "sa\n");
	else if (a > c && b < c)
		ft_ra(stack_a, "ra\n");
	else if (a < c && b > c)
	{
		ft_sa(stack_a, "sa\n");
		ft_ra(stack_a, "ra\n");
	}
	else if (a < b && b > c)
		ft_rra(stack_a, "rra\n");
}

void stack_to_array(t_list *stack, int *arr)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

void array_to_stack(t_list **stack , int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack, ft_lstnew(array[i]));
		i++;
	}
}
void sort_stack(t_list **stack)
{
	int size;
	int *arr;
	
	size = ft_lstsize(*stack);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		ft_error("malloc fail!\n");
	stack_to_array(*stack, arr);
	insertion_sort(arr, size);
	free_list(*stack);
	*stack = NULL;
	array_to_stack(stack, arr, size);
	free(arr);
}

void insertion_sort(int *array, int size)
{
	int i;
	int j;
	int key;
	
	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
	
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list *stack_b;
	// int size = 0;
	// int *array;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac < 2)
		ft_error("no args\n");
	parse_args(ac , av, &stack_a);
	// size = ft_lstsize(stack_a);
	// array = malloc(sizeof(int) * (size + 1)); 
	// if (size == 2 && stack_a->value > stack_a->next->value)
	// 	ft_sa(&stack_a, "sa\n");
	// if (size > 2)
	// 	ft_sort_three(&stack_a);
	ft_sa(&stack_a, "sa\n");
	ft_ra(&stack_a, "ra\n");
	printf("--------\n");
	t_list *tmp = stack_a;
	// printf("a\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
