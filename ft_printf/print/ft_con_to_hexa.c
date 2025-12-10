/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:19:55 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 13:08:50 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_to_hexa(unsigned long ptr, int letter, int *count)
{
	int		f;
	char	c;

	if (ptr == 0)
		return ;
	(*count)++;
	ft_convert_to_hexa(ptr / 16, letter, count);
	f = ptr % 16;
	c = f + '0';
	if (c >= '0' && c <= '9')
		write(1, &c, 1);
	else
	{
		c += letter;
		write(1, &c, 1);
	}
}

void	ft_convert_to_hexa_add(unsigned long ptr, int letter, int *count)
{
	int		f;
	char	c;

	if (ptr == 0)
		return ;
	(*count)++;
	ft_convert_to_hexa(ptr / 16, letter, count);
	f = ptr % 16;
	c = f + '0';
	if (c >= '0' && c <= '9')
		write(1, &c, 1);
	else
	{
		c += letter;
		write(1, &c, 1);
	}
}

void	check_before_con(unsigned long ptr, int letter, int *count)
{
	if (ptr == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	ft_convert_to_hexa(ptr, letter, count);
}
