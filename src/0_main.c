/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:45:32 by mamir             #+#    #+#             */
/*   Updated: 2024/07/19 18:51:16 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;

	a = ft_process(ac, av);
	if (!a || check_duplicates(a))
	{
		free_list(a);
		ft_error("double");
	}
	if (!is_sorted(a))
		ft_sort(&a);
	else
		ft_error("sorted");
	free_list(a);
}
