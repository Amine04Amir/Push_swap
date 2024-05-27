/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/05/27 11:07:23 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort_three(t_list **stack_a)
{
	t_list *A;
	t_list *B;
	t_list *C;
	
	A = *stack_a;
    B = (*stack_a)->next;
    C = (*stack_a)->next->next;
	if (A->value > B->value && B->value < C->value && A->value < C->value) /*case ;1*/
        ft_sa(stack_a);
    else if (A->value > B->value && B->value > C->value) /*case ;2*/
	{
        ft_sa(stack_a);
        ft_rra(stack_a);
    }
    else if (A->value > B->value && B->value < C->value && A->value > C->value) /*case ;3*/
        ft_ra(stack_a);
    else if (A->value < B->value && B->value > C->value && A->value < C->value) /*case ;4*/
	{
        ft_sa(stack_a);
        ft_ra(stack_a);
    }
    else if (A->value < B->value && B->value > C->value && A->value > C->value) /*case ;5*/
        ft_rra(stack_a);
}

int	main(int ac, char **av)
{
	t_list *stack_a = NULL;
	char **string;
	int i = 0;
	int nb = 0;
	
	if (ac != 2)
		ft_error();
	string = ft_split(av[1], ' ');
	while (string[i])
	{
		nb = ft_atoi(string[i]);
		ft_lstadd_back(&stack_a,  ft_lstnew(nb));
		i++;
	}
	ft_sort_three(&stack_a);
	t_list *tmp = stack_a;
	printf("stack:\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	
	return (0);
}