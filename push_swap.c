/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:09:57 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/13 22:49:15 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	free_all(t_stack *a, t_stack *b, int check)
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

static int	undup(t_stack *stack, int num)
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

static void	push_a(t_stack *a, t_node *node)
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

static int	create_a(t_stack *a, char **list, int index)
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
		push_a(a, node);
		index--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (-1);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return (free_all(a, b, 1));
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	a->name = 'a';
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	b->name = 'b';
	if (create_a(a, argv, argc - 1) == -1)
		return (free_all(a, b, -1));
	sort(a, b);
	free_all(a, b, 1);
}
