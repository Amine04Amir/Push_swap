/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:59:44 by mamir             #+#    #+#             */
/*   Updated: 2024/06/08 18:08:41 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		return (NULL);
	node->value = data;
	node->next = NULL;
	return (node);
}

int ft_lstsize(t_list *list)
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

void free_list(t_list *stack)
{
	t_list *tmp;
	
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}