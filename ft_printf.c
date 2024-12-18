/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2024/12/18 15:06:52 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (c);
}
void ft_putnbr(int nb)
{
    unsigned int nbr;

    if (nb < 0)
    {
        ft_putchar('-');
        nbr = nb * -1;
    }
    else
        nbr = nb;
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}

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
            if (*format == 'd')
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
                ft_putchar(*format);
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

int main(void)
{
    char *s = "abc";
    // char k = 'c';
    int num = 42;
    // printf("Hello %x, number %d\n", 87687678, num);
    printf("Hello %s, number %d\n", s, num);
    int result = printf("A%s, B %d\n", s, num);
    printf("result %d\n", result);

    // ft_putstr("hello\n");
    // ft_putstr("hello\n");
    // ft_putstr("hi\n");
    // ft_putnbr(num);
    // ft_putchar('\n');
    // ft_putchar(k);
    // ft_putchar('\n');
    return (0);
}