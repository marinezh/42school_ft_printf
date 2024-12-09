/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2024/12/09 17:57:07 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_putstr(char *str)
{
    int len;
    len = 0;
    while (str[len])
    {
        len++;
    }
    write(1, str, len);
}
// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

int ft_putchar(char c)
{
    if (write(1, &c, 1) != 1)
    {
        return -1; // Return -1 on failure (similar to EOF)
    }
    return (unsigned char)c;
}

void mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd')
            {
                printf("%d", va_arg(args, int));
            }
            else if (*format == 's')
            {
                printf("%s", va_arg(args, char *));
            }
        }
        else
        {
            ft_putchar(*format);
        }
        format++;
    }

    va_end(args);
}

int main(void)
{
    char *s = "cspdiuxX";
    int num = 42;
    mini_printf("Hello %s, number is %d\n", "World", num);
    // mini_printf("string %s", s);
    // ft_putstr("hello\n");
    // ft_putstr("hi\n");
    // ft_putstr("cspdiuxX%\n");
    return (0);
}