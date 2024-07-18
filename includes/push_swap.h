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
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*ft_lstlast(t_stack *list);
t_stack				*ft_lstnew(int data);
void				ft_lstadd_back(t_stack **list, t_stack *new);
int 				ft_lstsize(t_stack *list);
void 				free_list(t_stack *stack);

long				ft_atoi(const char *s);
char				**ft_split(char *s, char c);
int					ft_strlen(const char *str);
int					count_words(char *s, char c);
void 				ft_putstr(char *str);

void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void 				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void 				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void 				rrr(t_stack **stack_a, t_stack **stack_b);
void 				ss(t_stack **stack_a, t_stack **stack_b);
void 				rr(t_stack **stack_a, t_stack **stack_b);

void				sort_three(t_stack **stack_a);
int					is_sorted(t_stack *stack);
void 				parse_args(int ac, char **av, t_stack **stack_a);
void 				parse_arguments(int ac, char **av, t_stack **stack_a);
void 				parse_string(char *str, t_stack **stack_a);
int					check_duplicates(t_stack *stack_a, int num);
void				ft_error(char *str);


#endif