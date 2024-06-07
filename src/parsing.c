#include "../includes/push_swap.h"

void parse_args(int ac, char **av, t_list **stack_a)
{
	if (ac == 2)
		parse_string(av[1], stack_a);
	else
		parse_arguments(ac, av, stack_a);
}

void parse_arguments(int ac, char **av, t_list **stack_a)
{
	int i;
	int nums;

	i = 1;
	while (i < ac)
	{
		nums = ft_atoi(av[i]);
		if (check_duplicates(*stack_a, nums))
			ft_error("Duplicated number");
		ft_lstadd_back(stack_a, ft_lstnew(nums));
		i++;
	}
}

void parse_string(char *str, t_list **stack_a)
{
	int i;
	int nums;
	char **string;

	string = ft_split(str, ' ');
	i = 0;
	while (string[i])
	{
		nums = ft_atoi(string[i]);
		if (check_duplicates(*stack_a, nums))
			ft_error("Duplicated number");
		ft_lstadd_back(stack_a, ft_lstnew(nums));
		free(string[i]);
		i++;
	}
	free(string);
}

int check_duplicates(t_list *stack_a, int num)
{
	t_list *head;

	head = stack_a;
	while (head != NULL)
	{
		if (head->value == num)
			return 1;
		head = head->next;
	}
	return 0;
}