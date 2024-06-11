/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/06/09 12:40:05 by mamir            ###   ########.fr       */
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

void find_smallest(t_list **stack)
{
    t_list *current;
    int smallest;
    int i;
    int smallest_index;
    int size;

    if (!stack || !*stack)
        return;

    size = ft_lstsize(*stack);
    current = *stack;
    smallest = current->value;
    smallest_index = 0;
    i = 0;

    while (current)
    {
        if (current->value < smallest)
        {
            smallest = current->value;
            smallest_index = i;
        }
        current = current->next;
        i++;
    }

    if (smallest_index <= size / 2)
    {
        while (smallest_index--)
        {
            ra(stack);
        }
    }
    else
    {
        smallest_index = size - smallest_index;
        while (smallest_index--)
        {
            rra(stack);
        }
    }
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	find_smallest(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}	

void sort_five(t_list **stack_a, t_list **stack_b)
{
	find_smallest(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
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
	if (ft_lstsize(stack_a) == 2 && stack_a->value > stack_a->next->value)
		sa(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_a);
	t_list *tmp = stack_a;
	printf("-----------\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
