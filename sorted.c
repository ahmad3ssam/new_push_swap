#include "push_swap.h"

void	three_elems(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	while (1)
	{
		if (a->head->value > a->tail->value)
			rotate(a);
		else if (a->head->value > a->head->next->value)
			swap(a);
		else if (a->head->next->value > a->tail->value)
		{
			rotate(a);
			swap(a);
			rrotate(a);
		}
		else
			break;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*temp1;
	t_node	*temp2;

	if (!a || a->size <=1)
		return (1);
	temp1 = a->head;
	temp2 = temp1->next;
	while (temp2 != NULL)
	{
		if (temp1->value > temp2->value)
			return (0);
		temp1 = temp2;
		temp2 = temp2->next;
	}
	return (1);
}

int	find_min_b(t_stack *b, int *num)
{
	int	index;
	int	x;
	t_node	*temp;

	temp = b->head->next;
	index = 0;
	x = 0;
	*num = b->head->value;
	while (temp != NULL)
	{
		if (*num > temp->value)
		{
			index = x;
			*num = temp->value;
		}
		x++;
		temp = temp->next;
	}

	return (index);
}

int	ft_abs(int x, int y)
{
	if (x > y)
		return (x - y);
	return (y - x);
}

int	search_closer(t_stack *a, int num)
{
	int	diff;
	int	index;
	int	x;
	t_node	*temp;

	temp = a->head;
	x = 0;
	index = 0;
	diff = INT_MAX;
	while (temp != NULL)
	{
		if (diff < ft_abs(temp->value,num))
		{
			index = x;
			diff = ft_abs(temp->value,num);
		}
		x++;
		temp = temp->next;
	}
	return (index);
}

void	make_operas(t_stack *a, t_stack *b, int x, int y)
{
	if (x == 0 && y == 0)
	{
		pp(a, b);
		if (a->head->value < a->head->next->value)
			swap(a);
		return ;
	}
	if ((x > a->size / 2) && (y > b->size / 2))
		while(a->size >= x++ && b->size >= y++)
			rrr(a,b);
	else if ((x > a->size / 2) && (y <= b->size / 2))
		while (a->size >= x++ && 0 > y--)
		{
			rrotate(a);
			rotate(b);
		}
	else if ((x <= a->size / 2) && (y > b->size / 2))
		while (0 > x-- && b->size >= y++)
		{
			rotate(a);
			rrotate(b);
		}
	else
		while (0 > x-- && 0 > y--)
			rr(a, b);

	pp(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	int	index_a;
	int	index_b;
	int	num_b;

	if (is_sorted(a) || !b)
		return ;
	while (a->size > 3)
		pp(b, a);
	three_elems(a);

	while (b->size != 0 || !is_sorted(a))
	{
		ft_printf("%d\n",b->size);		
		
		index_b = find_min_b(b, &num_b);
		ft_printf("hi1%d %d\n",index_b,num_b);
		index_a = search_closer(a, num_b);
		ft_printf("hi2%d\n",index_a);
		make_operas(a, b, index_a, index_b);
		ft_printf("hi3\n");
	}
	while (a->head->value > a->head->next->value)
		rotate(a);
}
