/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/05 02:45:13 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int ft_handle_format(const char **format, va_list args)
{
    int chars_printed;

    chars_printed = 0;
    if (**format == 'c')
        chars_printed += ft_putchar(va_arg(args, int)); // Char is promoted to int
    else if (**format == 'd' || **format == 'i')
        chars_printed += ft_putnbr(va_arg(args, int)); // Integer argument
    else if (**format == 's')
        chars_printed += ft_putstr(va_arg(args, char *)); // String
    else if (**format == 'u')
        chars_printed += ft_put_unsigned(va_arg(args, unsigned int)); // Unsigned int
    else if (**format == 'x')
        chars_printed += ft_puthex(va_arg(args, unsigned int), 1); // Hexadecimal lowercase
    else if (**format == 'X')
        chars_printed += ft_puthex(va_arg(args, unsigned int), 0); // Hexadecimal uppercase
    else if (**format == 'p')
        chars_printed += ft_putptr(va_arg(args, void *)); // Pointer
    else if (**format == '%')
        chars_printed += ft_putchar('%'); // Handle % directly
    else
        chars_printed += ft_putchar('%'); // Handle invalid specifier by printing '%'
    
    return chars_printed;
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int total_chars;

    total_chars = 0;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            total_chars += ft_handle_format(&format, args);
        }
        else
        {
            total_chars += ft_putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (total_chars);
}
// int ft_printf(const char *format, ...)
// {
//     va_list args;

//     va_start(args, format);
//     //printf("Starting ft_printf with format: %s\n", format); // Debugging
//     while (*format)
//     {
//         // printf("test3: %c\n", format);
//         //printf("Current character: %c\n", *format); // Debugging
//         if (*format == '%')
//         {
//             format++;
//             if (*format == 'c')
//             {
//                 return ft_putchar(va_arg(args, int));
//             }
//             if (*format == 'd' || *format == 'i')
//             {
//                 int num = va_arg(args, int);
//                 return ft_putnbr(num);
//             }
//             if (*format == 's')
//             {
//                 char *str = va_arg(args, char *);
//                 return ft_putstr(str);
//             }
//             if (*format == 'u')
//             {
//                 unsigned int num = va_arg(args, unsigned int);
//                 return ft_put_unsigned(num);
//             }
//             if (*format == 'x')
//             {
//                 return ft_puthex(va_arg(args, unsigned int), 1);
//             }
//             if (*format == 'X')
//             {
//                 return ft_puthex(va_arg(args, unsigned int), 0);
//             }
//             if(*format == 'p')
//             {
//                 return ft_putptr(va_arg(args, void *));
//             }
//             else if (*format == '%')
//             {
//                 return ft_putchar('%'); // Print the '%' character
//             //     // ft_putchar(*format);
//             }
//         }
//         else
//         {
//             ft_putchar(*format);
//         }
//         format++;
//     }

//     va_end(args);
//     return (0);
// }

int main(void)
{
    // //1. string test
    // char *s = "cspdiuxX%";
    // ft_printf("string 1: %s\n", s);
    // printf("string 2: %s\n", s);
    // //2. char test
    // char k = 'w';
    // ft_printf("char 1: %c\n", k);
    // printf("char 2: %c\n", k);
    // //3. integer test
    // int num = 42;
    // ft_printf("num 1: %d\n", num);
    // printf("num 2: %d\n", num);
    // //4. pointer test
    // int x = 5;
    // int *ptr =&x;
    // ft_printf("ptr 1: %p\n", ptr);
    // printf("ptr 2: %p\n", ptr);
    // //5. hexagon test
    // unsigned int hex_num = 26475;
    // ft_printf("print hex 1 %x and %X\n", hex_num, hex_num);
    // printf("print hex 2 %x and %X\n", hex_num, hex_num);
    // //6. unsigned int
        //unsigned int n = 4252;
    // ft_printf("print unsigned 1 %u\n", n);
    // printf("print unsigned 2 %u\n", n);
    // //7. %
    // ft_printf("percent 1 %%\n");
    // printf("percent 2 %%\n");

    //8. Total chars check
    int total_chars1 = 0;
    int total_chars2 = 0;
    // int num = 42;
    // int *ptr = &num;
    
    // total_chars1 = ft_printf("%s,%d,%p\n", "one", num, ptr);
    // ft_putchar('\n');
    // total_chars2 = printf("%s,%d,%p\n", "two", num, ptr);
    total_chars1 = ft_printf("1%s,%s,%s\n", "one", "two", "3");
    ft_putchar('\n');
    total_chars2 = printf("2%s,%s,%s\n", "one", "two", "3");

    printf("total: %d\n", total_chars1);
    printf("total2: %d\n", total_chars2);
    return (0);
}