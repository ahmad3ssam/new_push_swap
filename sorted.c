#include "push_swap.h"

void	three_elems(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	while (1)
	{
		if (a->head->value > a->tail->value)
			rotate(a, 1);
		else if (a->head->value > a->head->next->value)
			swap(a);
		else if (a->head->next->value > a->tail->value)
		{
			rotate(a, 1);
			swap(a);
			rrotate(a, 1);
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
	temp2 = a->head->next;
	while (temp2 != NULL)
	{
		if (temp1->value > temp2->value)
			return (0);
		temp1 = temp1->next;
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
	x = 1;
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
		if (diff >= ft_abs(temp->value,num))
		{
			index = x;
			diff = ft_abs(temp->value,num);
		}
		x++;
		temp = temp->next;
	}
	return (index);
}

int	check_in_TailOrHead(t_stack *a, t_stack *b, int x, int y)
{
	if (x == 0 && y == 0)
	{
		pp(a, b);
		if (a->head->value > a->head->next->value)
			swap(a);
		return (1);
	}
	if (x == 0 && y == 1)
	{
		swap(b);
		if (a->head->value < b->head->value)
			rotate(a,1);
		pp(a,b);
		return (1);
	}
	if ((x ==  (a->size - 1)) && (y == 0))
	{
		if (a->tail->value > b->head->value)
			rotate(a, 1);
		pp(a, b);
		return (1);
	}
	if ((y == (b->size - 1)) && (x == 0))
	{
		rrotate(b, 1);
		pp(a, b);
		if (a->head->value > a->head->next->value)
			swap(a);
		return (1);
	}
	if ((y == (b->size - 1)) && (x == (a->size - 1)))
	{
		rrr(a, b);
		pp(a, b);
		if (a->head->value > a->head->next->value)
			swap(a);
		return (1);	
	}
	return (0);
}

void	make_operas(t_stack *a, t_stack *b, int x, int y)
{
	while (!check_in_TailOrHead(a,b,x,y))
	{
		if ((x > (a->size / 2) ))
		{
			while ((a->size - 1) > x)
			{
				x++;
				rrotate(a, 1);
			}
		}
		else
		{	while (0 < x)
			{
				rotate(a, 1);
				x--;
			}
		}
		if ((y > (b->size / 2)))
		{
			while ((b->size - 1) > y)
			{
				rrotate(b, 1);
				y++;
			}
		}
		else
		{
			while (0 < y)
			{
				rotate(b, 1);
				y--;
			}
		}
		// ft_printf("1");

	}
		// if ((x > a->size / 2) && (y > b->size / 2))
		// {
		// 	rrr(a,b);
		// 	x++;
		// 	y++;
		// }
		// else if ((x > a->size / 2) && (y <= b->size / 2))
		// {
		// 	rrotate(a, 1);
		// 	rotate(b, 1);
		// 	x++;
		// 	y--;
		// }
		// else if ((x <= a->size / 2) && (y > b->size / 2))
		// {
		// 	rotate(a, 1);
		// 	rrotate(b, 1);
		// 	y++;
		// 	x--;
		// }
		// else
		// {
		// 	rr(a, b);
		// 	x--;
		// 	y--;
		// }
	
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
	int x =  0;
	//Wwft_printf("%d\n",is_sorted(a));	
	while (b->size > 0)
	{
		//ft_printf("%d\n",b->size);		
		// t_node *temp = a->head; 
		// while (temp != NULL)
		// {
		// 	ft_printf("%d ",temp->value);
		// 	temp = temp->next;
		// }
		// ft_printf("\n");
		index_b = find_min_b(b, &num_b);
		// ft_printf("hi1 %d %d\n",index_b,num_b);
		index_a = search_closer(a, num_b);
		// ft_printf("hi2 %d\n",index_a);
		// if (x == 1)
			// break;
		
		make_operas(a, b, index_a, index_b);
		//ft_printf("heloo");
		x++;
		
	}
	while (a->head->value > a->tail->value)
		rotate(a, 1);
	// while (a->head->value < a->tail->value)
		// rrotate(a, 1);
}
