/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/08 18:29:16 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

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
// 		if (format[i] == '%' && ft_handle_type(format[i + 1]))
// 		{
// 			total_chars += ft_handle_format(format[i + 1], &args);
// 			i++;
// 		}
// 		else
// 		{
// 			total_chars += ft_putchar(format[i]);
// 			if (total_chars < 0 || format[i] < 0)
// 				return (-1);
// 		}	
// 		i++;
// 	}
// 	va_end(args);
// 	return (total_chars);
// }

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
		if (format[i] == '%')
		{
			if (ft_handle_type(format[i + 1])) // Valid specifier
			{
				total_chars += ft_handle_format(format[i + 1], &args);
				i++;
			}
			else // Invalid specifier or trailing `%`
			{
				va_end(args); // Clean up the va_list
				return (-1);  // Return -1 to match `printf` behavior
			}
		}
		else
		{
			total_chars += ft_putchar(format[i]); // Print regular characters
			if (total_chars < 0)
			{
				va_end(args);
				return (-1);
			}
		}
		i++; // Move to the next character
	}
	va_end(args); // Clean up the va_list after processing
	return (total_chars); // Return the total number of characters printed
}

// int main(void)
// {
// 	//1. string test
// 	char *s = "cspdiuxX%";
// 	ft_printf("string 1: %s\n", s);
// 	printf("string 2: %s\n", s);
// 	//2. char test
// 	char k = 'w';
// 	ft_printf("char 1: %c\n", k);
// 	printf("char 2: %c\n", k);
// 	//3. integer test
// 	int num = 42;
// 	ft_printf("num 1: %d, %d, %d, %d\n", 42, -42, 0, num);
// 	printf("num 2: %d, %d, %d, %d\n", 42, -42, 0, num);
// 	//4. pointer test
// 	int x = 5;
// 	int *ptr =&x;
// 	ft_printf("ptr 1: %p\n", ptr);
// 	printf("ptr 2: %p\n", ptr);
// 	//5. hexagon test
// 	unsigned int hex_num = 26475;
// 	ft_printf("print hex 1 %x and %X\n", hex_num, hex_num);
// 	printf("print hex 2 %x and %X\n", hex_num, hex_num);
// 	//6. unsigned int
// 	unsigned int n = 4252;
// 	ft_printf("print unsigned 1 %u\n", n);
// 	printf("print unsigned 2 %u\n", n);
// 	//7. %
// 	ft_printf("percent 1 %\n");
// 	printf("percent 2 %\n");
// 	ft_printf("percent 1 %%\n");
// 	printf("percent 2 %%\n");

// 	ft_printf(" invalid spec %a\n");
// 	printf("invalid spec 2 %a\n");

// 	//8. Total chars check
// 	int total_chars1 = 0;
// 	int total_chars2 = 0;
// 	int num2 = 42;
// 	int *ptr2 = &num2;
// 	ft_printf("pointer %p %p\n", ptr, ptr2);
// 	printf("pointer %p %p\n", 0, 0);

// 	total_chars1 = ft_printf("%s,%d,%p\n", "one", num2, ptr2);
// 	ft_putchar('\n');
// 	total_chars2 = printf("%s,%d,%p\n", "two", num2, ptr2);
// 	total_chars1 = ft_printf("1%s,%s,%s\n", "one", "two", "3");
// 	ft_putchar('\n');
// 	total_chars2 = printf("2%s,%s,%s\n", "one", "two", "3");

// 	printf("total: %d\n", total_chars1);
// 	printf("total2: %d\n", total_chars2);

// 	int i, j;
	
// 	i = printf("cspdiuxX%");
//     printf("%d\n", i);
    
//     j = ft_printf("cspdiuxX%");
//     printf("%d\n", j);

// 	// fclose(stdout);
// 	// int c = ft_printf("%u", 425); // Your custom implementation
// 	// int cc = printf("%u", 425);	  // Standard printf
// 	// freopen("/dev/tty", "w", stdout);

// 	// if (c == cc)
// 	// {
// 	// 	printf("\n case u: %d YES 🔥\n\n", c);
// 	// 	printf("\n case u: %d YES 🔥\n\n", cc);
// 	// 	ft_printf("ft: %u", 425);
// 	// 	printf("or: %u", 425);
// 	// }
// 	// else
// 	// {
// 	// 	printf("\n case u: %d NOOO 💀\n\n", c);
// 	// 	printf("\n case u: %d NOOO 💀\n\n", cc);
// 	// 	ft_printf("ft: %u", 425);
// 	// 	printf("or: %u", 425);
// 	// }
// 	// return (0);
// }