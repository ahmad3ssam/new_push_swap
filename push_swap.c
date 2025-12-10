#include "push_swap.h"

int	free_all(t_stack *a, t_stack *b, int check)
{
	t_node	*temp;
	t_node	*current;

	current = a->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(a);
	current = b->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(b);
	if (check == -1)
		ft_printf("Error\n");
	return (0);
}

void	push_a(t_stack *a, t_node *node)
{
	if (!(a)->head)
	{
		(a)->head = node;
		(a)->tail = node;
		(a)->size = 1;
	}
	else
	{
		node->next = (a)->head;
		(a)->head = node;
		(a)->size += 1;
	}
}

int	create_a(t_stack *a, char **list, int index)
{
	long	num;
	t_node	*node;

	while (index > 0)
	{
		num = ft_atoi(list[index]);
		if (num == LONG_MAX || undup(a, num) == 1)
			return (-1);
		node = malloc(sizeof(t_node));
		node -> value = num;
		node -> next = NULL;
		push_a(a,node);
		index--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if(argc == 1)
        	return (-1);
	t_stack *a = malloc(sizeof(t_stack));
    	a->head = NULL;
    	a->tail = NULL;
    	a->size = 0;
	a->name = 'a';
    	t_stack *b = malloc(sizeof(t_stack));
    	b->head = NULL;
    	b->tail = NULL;
	b->size = 0;
	b->name = 'b';
	if(create_a(a,argv,argc-1) == -1)
        	return (free_all(a,b,-1));

	//pp(b,a);
	//pp(b,a);
	//pp(b,a);
	//ss(b,a);
	//swap(a);
//	rrr(a,b);

	//three_elems(a);
	//ft_printf("%d\n",is_sorted(a));
	sort(a,b);
	t_node *temp = a->head;
     	while (temp)
     	{
        	 ft_printf("stack a values: %d\n",temp->value);
        	 temp = temp->next;
	}
	temp = b->head;
     	while (temp)
     	{
        	 //ft_printf("stack b values: %d\n",temp->value);
        	 temp = temp->next;
	}

	//ss(a,b);

	//if(a->tail != NULL)
   //		ft_printf("size a %d\n",a->size);
	//if(a->head != NULL)
//		ft_printf("size b %d",b->size);
    //free(a);
    //free(b);
    free_all(a,b,1);
}
