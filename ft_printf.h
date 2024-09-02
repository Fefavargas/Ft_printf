/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:40:53 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/14 21:03:32 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h> //size_t
# include <stdarg.h> // va_list

int	ft_printf(const char *str, ...);
int	print_string_count(char *str);
int	print_char_count(char x);
int	print_hex_count(unsigned long x, char type);

#endif
