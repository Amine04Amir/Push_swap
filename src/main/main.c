/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/08/10 13:59:50 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		free(tab[j++]);
	free(tab);
}

void	split_args(t_stack **a, int ac, char **av)
{
	char	**tab;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (is_empty(av[i]))
			ft_error(a);
		tab = ft_split(av[i], ' ', a);
		init_stack_a(a, tab);
		free_tab(tab);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !(av[1][0])))
		return (0);
	split_args(&a, ac, av);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
