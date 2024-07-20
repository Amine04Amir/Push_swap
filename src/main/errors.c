#include "../includes/push_swap.h"

int ft_duplicates(t_stack *a, int n)
{
    if (!a)
        return (0);
	while (a)
	{
		if (a->nbr == n)
			return 1;
		a = a->next;
	}
	return 0;
}

int syntax_errors(char *str)
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+' || *str == '-') && !(*str >= '0' && *str <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return 1;
    }
    return (0);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;
    
    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        current->nbr = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void ft_error(t_stack **stack)
{
    free_stack(stack);
    write(2, "Error!\n", 8);
    exit(1);
}