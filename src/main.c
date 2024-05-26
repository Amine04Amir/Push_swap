/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/05/26 17:04:34 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_error()
{
	write(2, "Error!\n", 8);
	exit(1);
}

t_list	*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new;
}

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
		return NULL;
	node->value = data;
	node->next = NULL;
    return node;
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
	// ft_sa(&stack_a);
	// ft_ra(&stack_a);
	// ft_rra(&stack_a);
	t_list *stack_b = NULL;
	t_list *tmp = stack_a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	printf("stack_a:\n");
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("stack_b:\n%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	return (0);
}