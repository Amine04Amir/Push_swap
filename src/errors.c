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
