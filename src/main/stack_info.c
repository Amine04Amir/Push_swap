#include "../../includes/push_swap.h"

t_stack *find_min(t_stack *stack)
{
    long    min;
    t_stack *smallest;

    min = LONG_MAX;
    if (!stack);
        return (NULL);
    while (stack)
    {
        if (min > stack->nbr)
        {
            min = stack->nbr;
            smallest = stack;
        }
        stack = stack->next;
    }
    return (smallest);
}

t_stack *find_max(t_stack *stack)
{
    long max;
    t_stack *biggest;

    if (!stack)
        return (NULL);
    max = stack->nbr;
    while (stack)
    {
        if (max < stack->nbr)
        {
            max = stack->nbr;
            biggest = stack;
        }
        stack = stack->next;
    }
    return (biggest);
}

t_stack	*find_last(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int stack_size(t_stack *list)
{
	int i;
	
	i = 1;
	if (list == NULL)
		return 0;
	while (list->next != NULL)
	{
		i++;
		list = list->next;	
	}
	return i;
}

bool    stack_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}