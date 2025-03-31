/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:44:31 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/31 21:47:16 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (1);
}
int ft_putstr(char *str)
{
    int len;
    len = 0;
    if (!str)
        return (write(1, "(null)", 6));
    while (str[len])
        len++;
    return (write(1, str, len));
}
int ft_putnbr(int nb)
{
    unsigned int nbr;
	int count;

	count = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nbr = -nb;
		count++;
    }
    else
        nbr = nb;
    if (nbr >= 10)
		 count += ft_putnbr(nbr / 10);
    count += ft_putchar(nbr % 10 + '0');

	return (count);
}
int ft_puthex(unsigned int n)
{
    char *hex_digits;
    int count = 0;

    hex_digits = "0123456789abcdef";
 
    if (n == 0) 
    {
        count += ft_putchar('0');
        return count;
    }
 
    if (n >= 16)
        count =count + ft_puthex(n / 16);
    count += ft_putchar(hex_digits[n % 16]);

    return count;
}
int ft_printf(char *str, ...)
{
    va_list args;
    size_t i = 0;
    int total_chars = 0;

    va_start(args, str);
    while (str[i])
    {
        if(str[i] == '%')
        {
            if (str[i + 1] == 's')
            {
                total_chars += ft_putstr(va_arg(args, char *));
            }
               
            else if (str[i + 1] == 'd')
            {
               total_chars += ft_putnbr(va_arg(args, int));
            }
            else if (str[i + 1] == 'x')
            {
                total_chars += ft_puthex(va_arg(args, unsigned int));
            }
            else
                total_chars += ft_putchar(str[i + 1]); 
            i +=2;
        }
        else
        {
            total_chars += ft_putchar(str[i]);
            i++;
        }
    }

    va_end(args);
    return total_chars;
}

int main()
{
    // char *str = "hello\n";
    // int num = 42;
    // ft_putstr(str);
    
    // ft_putnbr(num);
    // write(1, "\n", 1);

    ft_printf("Hello %s\n", "toto");
    //out:Hello toto$

    ft_printf("Magic %s is %d\n", "number", 42);
    //out:Magic number is 42%

    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    //out:Hexadecimal for 42 is 2a$
    return 0;
}