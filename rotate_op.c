#include "push_swap.h"

void	rotate(t_stack *stack, int print)
{
	t_node	*temp;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->head->next;
	stack->head->next = NULL;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = temp;
	if(print)
		ft_printf("r%c\n",stack->name);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	rrotate(t_stack *stack, int print)
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
	if(print)
		ft_printf("rr%c\n",stack->name);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a, 0);
	rrotate(b, 0);
	ft_printf("rrr\n");
}
