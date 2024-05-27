/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/05/27 13:35:41 by mamir            ###   ########.fr       */
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
	char	**string;
	int		i;
	int		nb;
	t_list	*tmp;

	stack_a = NULL;
	i = 0;
	nb = 0;
	if (ac != 2)
		ft_error();
	string = ft_split(av[1], ' ');
	while (string[i])
	{
		nb = ft_atoi(string[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(nb));
		i++;
	}
	ft_sort_three(&stack_a);
	tmp = stack_a;
	printf("stack:\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
