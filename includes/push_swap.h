#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int 			push_cost;
	bool 			above_median;
	bool 			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*  *** handle errors *** */

int			ft_duplicates(t_stack *a, int n);
int			syntax_errors(char *str);
void		free_stack(t_stack **stack);
void		ft_error(t_stack **stack);

/* *** stack init *** */

/* *** utils *** */

/* *** commands *** */

void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void 			ra(t_stack **stack_a);
void 			rb(t_stack **stack_b);
void 			rr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void 			rrr(t_stack **stack_a, t_stack **stack_b);

/* *** Algo *** */


#endif