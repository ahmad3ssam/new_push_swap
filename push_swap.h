/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:10:11 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/13 22:49:37 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/print/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int	value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	char		name;
}	t_stack;

void	pp(t_stack *dest, t_stack *src);
void	ss(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, int print);
void	rr(t_stack *a, t_stack *b);
void	rrotate(t_stack *stack, int print);
void	rrr(t_stack *a, t_stack *b);
void	three_elems(t_stack *a);
void	sort(t_stack *a, t_stack *b);
int	is_sorted(t_stack *a);
#endif
