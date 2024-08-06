/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:49:46 by mamir             #+#    #+#             */
/*   Updated: 2024/08/06 10:08:21 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
	{
		ra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	else if ((*a)->nbr < (*a)->next->nbr
		&& (*a)->next->nbr > (*a)->next->next->nbr)
	{
		rra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	else if ((*a)->next->next->nbr > (*a)->nbr
		&& (*a)->next->next->nbr > (*a)->next->nbr)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
}
