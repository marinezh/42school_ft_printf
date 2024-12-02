/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2024/12/02 15:20:05 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

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
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}
int main(void)
{
    mini_printf("Hello %s, number is %d\n", "World", 42);
    return (0);
}