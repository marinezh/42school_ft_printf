/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/03 21:41:18 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"


int ft_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    printf("Starting ft_printf with format: %s\n", format); // Debugging
    while (*format)
    {
        // printf("test3: %c\n", format);
        printf("Current character: %c\n", *format); // Debugging
        if (*format == '%')
        {

            format++;
            if (*format == 'c')
            {
                ft_putchar(va_arg(args, int));
            }
            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                ft_putnbr(num);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                ft_putstr(str);
            }
            else
            {
                ft_putchar('%'); // Print the '%' character
                // ft_putchar(*format);
            }
        }
        else
        {
            ft_putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (0);
}

// int main(void)
// {
//     char *s = "abc";
//     char k = 'w';
//     int num = 42;
//     char *ptr;
//     char *ptr1;
//     unsigned int hex_num = 0x26475;
//     ptr1 = NULL;
//     ptr = "Pointer 12345";
//     printf("pointer check %p\n , %p\n", ptr, ptr1);
//     // printf("Hello %x, number %d\n", 87687678, num);
//     printf("Hello %s, char is %c, number %d\n", s, k, num);
//     int result = printf("A%s, B %d\n", s, num);
//     printf("result %d\n", result);
//     printf("print hex %x and %X\n", hex_num, hex_num);
//     // ft_putstr("hello\n");
//     // ft_putstr("hello\n");
//     // ft_putstr("hi\n");
//     // ft_putnbr(num);
//     // ft_putchar('\n');
//     // ft_putchar(k);
//     // ft_putchar('\n');
//     return (0);
// }