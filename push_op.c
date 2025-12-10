#include "push_swap.h"

void	pp(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	if (src -> head == src->tail)
		src->tail = NULL;
	src -> head = temp -> next;
	temp -> next = dest->head;
	dest -> head = temp;
	if (dest->tail == NULL)
		dest->tail = temp;
	dest->size++;
	src->size--;
	ft_printf("p%c\n",dest->name);
}
