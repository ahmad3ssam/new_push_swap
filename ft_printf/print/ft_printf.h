/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:40:27 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 13:09:23 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *c, ...);
int		ft_putunbr(long n);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
void	ft_print_num(long n, int *count);
int		ft_putchar(char c);
int		ft_putaddr(void *p);
void	ft_convert_to_hexa(unsigned long ptr, int letter, int *count);
size_t	ft_strlen(const char *s);
void	check_before_con(unsigned long ptr, int letter, int *count);
void	ft_convert_to_hexa_add(unsigned long ptr, int letter, int *count);

#endif
