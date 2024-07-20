#include "../includes/push_swap.h"

int check_duplicates(t_stack *a)
{
	t_stack *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return 1;
			tmp = tmp->next;
		}
		a = a->next;
	}
	return 0;
}

int is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return 0;
		stack = stack->next;
	}
	return 1;
}

t_stack *ft_string_process(char **av)
{
    t_stack *a;
    char **tmp;
    int i;
    int j;

    a = NULL;
    i = 0;
    tmp = ft_split(av[1], ' ');
    while (tmp[i])
    {
        j = ft_atoi(tmp[i]);
        ft_lstadd_back(&a, ft_lstnew(j));
        i++;
    }
    return (a);
}

t_stack *ft_process(int ac, char **av)
{
    t_stack *a;
    int i;
    int j;

    a = NULL;
    i = 1;
    if (ac < 2)
        ft_error("insufisent args");
    if (ac == 2)
        a = ft_string_process(av);
    else
    {
        while (i < ac)
        {
            j = ft_atoi(av[i]);
            ft_lstadd_back(&a, ft_lstnew(j));
            i++;
        }
    }
    return (a);
}