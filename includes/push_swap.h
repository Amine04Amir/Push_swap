#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

 
typedef struct s_list
{
    int value; 
    struct s_list *next;
}   t_list; 


long	ft_atoi(const char *s);
char	**ft_split(char *s, char c);
int ft_strlen(const char *str);
int count_words(char *s, char c);
void ft_sa(t_list **stack_a);
void ft_ra(t_list **stack_a);
t_list	*ft_lstlast(t_list *list);
#endif