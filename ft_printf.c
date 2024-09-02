/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:19:20 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/21 15:59:30 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_pointer_count(void *p)
{
	if (!p)
		return (print_string_count("(nil)"));
	ft_putstr_fd("0x", 1);
	return (2 + print_hex_count((unsigned long)p, 'x'));
}

int	print_unsigned_count(unsigned int x)
{
	if (x < 10)
		return (print_char_count(x + '0'));
	return (print_unsigned_count(x / 10) + print_unsigned_count(x % 10));
}

int	print_number_count(int x)
{
	if (x == -2147483648)
	{
		print_string_count("-2147483648");
		return (ft_strlen("-2147483648"));
	}
	if (x < 0)
	{
		x *= -1;
		print_char_count('-');
		return (1 + print_unsigned_count((unsigned int)x));
	}
	return (print_unsigned_count((unsigned int)x));
}

static int	print_specifier_count(const char type, va_list args)
{
	if (type == 'c')
		return (print_char_count(va_arg(args, int)));
	else if (type == 's')
		return (print_string_count(va_arg(args, char *)));
	else if (type == 'p')
		return (print_pointer_count(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (print_number_count(va_arg(args, int)));
	else if (type == 'u')
		return (print_unsigned_count(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (print_hex_count(va_arg(args, unsigned int), type));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if(!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX", str[i + 1]))
				count += print_specifier_count(str[i + 1], args);
			else
				count += print_char_count(str[i]);
			i++;
		}
		else
			count += print_char_count(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
 #include <stdio.h>
//#include <stdarg.h> // va_list
//#include <unistd.h> //write()
int	main(void)
{
	//char	*s1;
	//unsigned int x = 15436;

	printf("prinft: %i\n", 0);
	ft_printf("ft_printf: %i\n", 0);
	return (0);
}*/
