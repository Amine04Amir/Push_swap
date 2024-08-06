/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:59:28 by mamir             #+#    #+#             */
/*   Updated: 2024/08/05 14:00:11 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	
	len_a = stack_size(a);
	len_b = stack_size(b);

	while (a) 
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index); 
		if (a->target_node->above_median) 
			a->push_cost += a->target_node->index; 
		else 
			a->push_cost += len_b - (a->target_node->index);
		a = a->next; 
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

// void    ft_calc_movtg(t_stack *stack_a, t_stack *stack_b, t_stack *node)
// {
//     if (node->above_median == 1 && node->target_node->above_median == 1)
//     {
//         if (node->index < node->target_node->index)
//             node->push_cost -= node->index;
//         else
//             node->push_cost -= node->target_node->index;
//     }
//     else if (node->above_median == 0 && node->target_node->above_median == 0)
//     {
//         if (ft_stacklength(stack_a) - node->index 
//             < ft_stacklength(stack_b) - node->target_node->index)
//             node->push_cost -= stack_size(stack_a) - node->index;
//         else
//             node->push_cost -= stack_size(stack_b) - node->target_node->index;
//     }
// }
