#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->head->next;
	stack->head->next = NULL;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = temp;
	ft_printf("r%c\n",stack->name);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rrotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = temp;
	ft_printf("rr%c\n",stack->name);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
}
