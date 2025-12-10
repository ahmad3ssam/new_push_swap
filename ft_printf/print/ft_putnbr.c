/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:17:36 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/17 11:47:24 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(long n, int *count)
{
	char	c;

	if (n == 0)
		return ;
	(*count)++;
	ft_print_num(n / 10, count);
	c = ('0' + (n % 10));
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += 11;
		write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count++;
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		count++;
		write(1, "0", 1);
		return (count);
	}
	ft_print_num(n, &count);
	return (count);
}
