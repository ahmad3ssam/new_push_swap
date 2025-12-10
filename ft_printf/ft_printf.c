/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:39:52 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 13:12:40 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print/ft_printf.h"

int	ft_print_it(char c, va_list args, int *count)
{
	if (c == 'c')
		(*count) += ft_putchar(va_arg(args, int));
	else if (c == 's')
		(*count) += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		(*count) += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		(*count) += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		(*count) += ft_putunbr(va_arg(args, int));
	else if (c == 'p')
		(*count) += ft_putaddr(va_arg(args, void *));
	else if (c == 'x')
		check_before_con(va_arg(args, unsigned int), 39, count);
	else if (c == 'X')
		check_before_con(va_arg(args, unsigned int), 7, count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	return (1);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, c);
	if (!c)
		return (-1);
	i = 0;
	count = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			count += ft_putchar(c[i]);
		}
		else if (c[i] == '%')
			i += ft_print_it(c[i + 1], args, &count);
		i++;
	}
	va_end(args);
	return (count);
}
