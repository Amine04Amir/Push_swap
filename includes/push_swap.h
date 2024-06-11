#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstlast(t_list *list);
t_list				*ft_lstnew(int data);
void				ft_lstadd_back(t_list **list, t_list *new);
int 				ft_lstsize(t_list *list);
void 				free_list(t_list *stack);

long				ft_atoi(const char *s);
char				**ft_split(char *s, char c);
int					ft_strlen(const char *str);
int					count_words(char *s, char c);
void 				ft_putstr(char *str);

void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
void 				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void 				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void 				rrr(t_list **stack_a, t_list **stack_b);
void 				ss(t_list **stack_a, t_list **stack_b);
void 				rr(t_list **stack_a, t_list **stack_b);

void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_three(t_list **stack_a);
void 				find_smallest(t_list **stack);

void 				parse_args(int ac, char **av, t_list **stack_a);
void 				parse_arguments(int ac, char **av, t_list **stack_a);
void 				parse_string(char *str, t_list **stack_a);
int					check_duplicates(t_list *stack_a, int num);
void				ft_error(char *str);

#endif