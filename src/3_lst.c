/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:59:44 by mamir             #+#    #+#             */
/*   Updated: 2024/07/18 18:50:40 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*last;

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

t_stack	*ft_lstnew(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->nbr = data;
	node->next = NULL;
	return (node);
}

int ft_lstsize(t_stack *list)
{
	int i;
	
	i = 1;
	if (list == NULL)
		return 0;
	while (list->next != NULL)
	{
		i++;
		list = list->next;	
	}
	return i;
}

void free_list(t_stack *stack)
{
	t_stack *tmp;
	
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}