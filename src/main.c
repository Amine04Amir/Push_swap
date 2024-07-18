/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/07/18 17:24:45 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int a = (*stack_a)->nbr;
    int b = (*stack_a)->next->nbr;
    int c = (*stack_a)->next->next->nbr;

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

int is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return 0;
		stack = stack->next;
	}
	return 1;
}

int	main(int ac, char **av)
{
	t_stack	*stk_a;
	t_stack *stk_b;

	stk_a = NULL;
	stk_b = NULL;
	
	if (ac < 2)
		ft_error("no args\n");
	parse_args(ac , av, &stk_a);

	if (is_sorted(stk_a))
		ft_error("sorted!");
	else
	{
		if (ft_lstsize(stk_a) == 2 && stk_a->nbr > stk_a->next->nbr)
			sa(&stk_a);
		else if (ft_lstsize(stk_a) == 3)
			sort_three(&stk_a);
		// else
        // {
        //     sort_stack(&stk_a, &stk_b);
        // }
	}
	t_stack *tmp = stk_a;
	printf("----sort----\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}
