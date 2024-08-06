/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:49:28 by mamir             #+#    #+#             */
/*   Updated: 2024/08/06 11:23:00 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*  *** errors *** */
int					ft_duplicates(t_stack *a, int n);
int					syntax_errors(char *str);
void				free_stack(t_stack **stack);
void				ft_error(t_stack **stack);
/* *** stack / nodes  *** */
char				**split(char *str, char c);
void				init_stack_a(t_stack **a, char **av);
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);
void				min_on_top(t_stack **a);
/* *** utils *** */
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_last(t_stack *list);
t_stack				*get_cheapest(t_stack *stack);
void				current_index(t_stack *stack);
int					stack_size(t_stack *list);
bool				stack_sorted(t_stack *stack);
long				ft_atol(char *s);
/* *** commands *** */
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
/* *** Algo *** */
void				sort_three(t_stack **stack);
void				sort_stacks(t_stack **a, t_stack **b);

#endif