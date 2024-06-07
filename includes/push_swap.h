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
void				ft_error(char *str);

long				ft_atoi(const char *s);
char				**ft_split(char *s, char c);
int					ft_strlen(const char *str);
int					count_words(char *s, char c);

void				ft_sa(t_list **stack_a);
void				ft_sb(t_list **stack_b);
void				ft_ra(t_list **stack_a);
void				ft_rb(t_list **stack_b);
void				ft_rra(t_list **stack_a);
void				ft_rrb(t_list **stack_b);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_pb(t_list **stack_a, t_list **stack_b);

void				ft_sort_three(t_list **stack_a);

void 				parse_args(int ac, char **av, t_list **stack_a);
int					check_duplicates(t_list *stack_a, int num);

#endif