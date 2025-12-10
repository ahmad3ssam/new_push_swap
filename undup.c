#include "push_swap.h"

int	undup(t_stack *stack, int num)
{
	t_node	*temp;

	temp = stack->head;
	while (temp != NULL)
	{
		if (temp->value == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}
