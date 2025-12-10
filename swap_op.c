#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->head->next;
	stack->head->next = temp->next;
	temp->next = stack->head;
	stack->head = temp;
	if (stack->size == 2)
		stack->tail = temp->next;
	ft_printf("s%c\n",stack->name);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
