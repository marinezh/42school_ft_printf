/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/10 12:04:58 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

static int ft_handle_format(const char format, va_list *args)
{
	int chars_printed;

	chars_printed = 0;
	if (format == 'c')
		chars_printed += ft_putchar(va_arg(*args, int));
	else if (format == 'd' || format == 'i')
		chars_printed += ft_putnbr(va_arg(*args, int));
	else if (format == 's')
		chars_printed += ft_putstr(va_arg(*args, char *));
	else if (format == 'u')
		chars_printed += ft_put_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x')
		chars_printed += ft_puthex(va_arg(*args, unsigned int), 1);
	else if (format == 'X')
		chars_printed += ft_puthex(va_arg(*args, unsigned int), 0);
	else if (format == 'p')
		chars_printed += ft_putptr(va_arg(*args, void *));
	else if (format == '%')
		chars_printed += ft_putchar('%');
	else
		chars_printed += ft_putchar('%'); // Handle invalid specifier by printing '%'

	return chars_printed;
}
static int ft_handle_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		total_chars;

	total_chars = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_handle_type(format[i + 1]))
		{
			total_chars += ft_handle_format(format[i + 1], &args);
			i++;
		}
		else
		{
			total_chars += ft_putchar(format[i]);
			if (total_chars < 0)
				return (-1);
		}	
		i++;
	}
	va_end(args);
	return (total_chars);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;        
// 	size_t	i;            
// 	int		total_chars;  

// 	total_chars = 0;      
// 	i = 0;                 
// 	va_start(args, format); 
// 	while (format[i]) 
// 	{
// 		if (format[i] == '%')
// 		{
// 			if (ft_handle_type(format[i + 1])) // Valid specifier
// 			{
// 				total_chars += ft_handle_format(format[i + 1], &args);
// 				i++;
// 			}
// 			else // Invalid specifier or trailing `%`
// 			{
// 				va_end(args); // Clean up the va_list
// 				return (-1);  // Return -1 to match `printf` behavior
// 			}
// 		}
// 		else
// 		{
// 			total_chars += ft_putchar(format[i]); // Print regular characters
// 			if (total_chars < 0)
// 			{
// 				va_end(args);
// 				return (-1);
// 			}
// 		}
// 		i++; // Move to the next character
// 	}
// 	va_end(args); // Clean up the va_list after processing
// 	return (total_chars); // Return the total number of characters printed
// }

