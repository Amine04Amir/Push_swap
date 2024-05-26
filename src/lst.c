#include "../includes/push_swap.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new;
}

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
		return NULL;
	node->value = data;
	node->next = NULL;
    return node;
}

