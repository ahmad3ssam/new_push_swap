/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:18:48 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/17 11:39:02 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n = 4294967296 + n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_print_num(n, &count);
	return (count);
}
