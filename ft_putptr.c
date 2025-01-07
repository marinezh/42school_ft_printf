/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:40 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/07 17:31:13 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_puthexx(unsigned long num)
{
	int count = 0;
	const char *hex_digits = "0123456789abcdef";

	if (num >= 16)
	{
		count += ft_puthexx(num / 16); // Print higher-order digits
	}
	count += ft_putchar(hex_digits[num % 16]); // Print the current digit

	return count;
}

// Function to print a pointer in hexadecimal format
int ft_putptr(void *ptr)
{
	int count = 0;

	if (!ptr)
		return (ft_putstr("(nil)"));
	// return (-1);
	count += ft_putstr("0x");				 // Print the "0x" prefix
	count += ft_puthexx((unsigned long)ptr); // Print the address in hexadecimal
	if (count < 0)
		return (-1);
	return count;
}
// static int print_long_hex(unsigned long int n)
// {
// 	if (n < 16)
// 		return (print_hex_char(n, 1));
// 	else
// 		return (print_long_hex(n / 16) + print_hex_char(n % 16, 1));
// }

// int ft_putptr(void *p)
// {
// 	return (write(1, "0x", 2) + print_long_hex((unsigned long int)p));
// }
// #include <stdio.h>

// int main()
// {
//     int x = 425;
//     int *ptr = &x;
//     int count;
//     int count2;

//     count = ft_putptr(ptr); // Output: 0x[address]
//     printf(" -> %d characters\n", count);

//     count = ft_putptr(NULL); // Output: 0x0
//     printf(" -> %d characters\n", count);

// 	count2 = printf("printf result: %p", ptr);
// 	printf("printf: %d", count2);

//     return 0;
// }
