/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:06:00 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/13 22:51:14 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			break ;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*temp1;
	t_node	*temp2;

	if (!a || a->size <= 1)
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
	int		index;
	int		x;
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
	int		diff;
	int		index;
	int		x;
	t_node	*temp;

	temp = a->head;
	x = 0;
	index = 0;
	diff = INT_MAX;
	while (temp != NULL)
	{
		if (diff >= ft_abs(temp->value, num))
		{
			index = x;
			diff = ft_abs(temp->value, num);
		}
		x++;
		temp = temp->next;
	}
	return (index);
}

int	check_in_tail0rhead(t_stack *a, t_stack *b, int x, int y)
{
	if ((x > 0 && x < a->size - 1) || (y > 0 && y < b->size - 1))
		return (0);
	if (x == 0 && y == 1)
	{
		swap(b);
		if (a->head->value < b->head->value)
			rotate(a, 1);
	}
	if ((x == a->size - 1) && (y == 0))
		if (a->tail->value > b->head->value)
			rrotate(a, 1);
	if ((y == (b->size - 1)) && (x == 0))
		rrotate(b, 1);
	pp(a, b);
	if (a->head->value > a->head->next->value)
		swap(a);
	return (1);
}

void	make_operas(t_stack *a, t_stack *b, int x, int y)
{
	while (!check_in_tail0rhead(a, b, x, y))
	{
		while ((x > (a->size / 2) && (a->size - 1) >= x) &&
			((y > (b->size / 2)) && (b->size - 1) >= y))
		{
			x++;
			y++;
			rrr(a, b);
		}
		while (((y > (b->size / 2)) && (b->size - 1) > y))
		{
			rrotate(b, 1);
			y++;
		}
		while (((x > (a->size / 2) && (a->size - 1) > x)))
		{
			rrotate(a, 1);
			x++;
		}
		while ((x <= (a->size / 2) && x > 0) && (y <= (b->size / 2) && y > 0))
		{
			x--;
			y--;
			rr(a, b);
		}
		while (y <= (b->size / 2) && y > 0)
		{
			rotate(b, 1);
			y--;
		}
		while ((x <= (a->size / 2) && x > 0))
		{
			rotate(a, 1);
			x--;
		}
	}
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
	while (b->size > 0)
	{
		index_b = find_min_b(b, &num_b);
		index_a = search_closer(a, num_b);
		make_operas(a, b, index_a, index_b);
	}
	while (a->head->value > a->tail->value)
		rotate(a, 1);
}
