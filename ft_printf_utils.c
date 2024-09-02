/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:40:03 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/19 20:03:57 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_string_count(char *str)
{
	if (!str)
		return (print_string_count("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_char_count(char x)
{
	ft_putchar_fd(x, 1);
	return (1);
}

int	print_hex_count(unsigned long x, char type)
{
	if (x < 10)
		return (print_char_count(x + '0'));
	if (type == 'X' && x < 16)
		return (print_char_count(x - 10 + 'A'));
	if (type == 'x' && x < 16)
		return (print_char_count(x - 10 + 'a'));
	return (print_hex_count(x / 16, type) + print_hex_count(x % 16, type));
}
