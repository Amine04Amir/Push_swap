#include "../includes/push_swap.h"

void sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}
void ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

