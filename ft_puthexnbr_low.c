/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:30:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2024/12/19 19:42:23 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// void ft_puthexnbr(int nb)
// {
//     unsigned int nbr;

//     if (nb < 0)
//     {
//         ft_putchar('-');
//         nbr = nb * -1;
//     }
//     else
//         nbr = nb;
//     if (nbr >= 10)
//         ft_putnbr(nbr / 10);
//     ft_putchar(nbr % 10 + '0');
// }
// #include "ft_printf.h"
int ft_putchar_fd(char c)
{
    return (write(1, &c, 1));
}
int ft_puthex_fd(unsigned int nb, char format)
{
    int count;
    char *hex;

    count = 0;
    if (format == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if (nb >= 16)
        count = ft_puthex_fd((nb / 16), format);
    if (ft_putchar_fd(hex[nb % 16]) < 0)
        return (-1);
    return (count + 1);
}
// void ft_puthex_fd(int decimal)
// {
//     char *hex;

//     if (decimal == 0) // Handle special case for 0
//     {
//         hex[0] = '0';
//         hex[1] = '\0';
//         return;
//     }

//     int index = 0;

//     while (decimal > 0)
//     {
//         int remainder = decimal % 16; // Get the remainder
//         if (remainder < 10)
//             hex[index++] = '0' + remainder; // Convert 0-9 to characters
//         else
//             hex[index++] = 'A' + (remainder - 10); // Convert 10-15 to 'A'-'F'

//         decimal /= 16; // Divide the number by 16
//     }

//     hex[index] = '\0'; // Null-terminate the string

//     // Reverse the string since we calculated it in reverse order
//     for (int i = 0; i < index / 2; i++)
//     {
//         char temp = hex[i];
//         hex[i] = hex[index - i - 1];
//         hex[index - i - 1] = temp;
//     }
// }
// int main()
// {
//     int num = 255;
//     // char hex[20];
//     //  printf("Decimal: %d\n", num);     // Output: Decimal: 255
//     //  printf("Hexadecimal: %x\n", num); // Output: Hexadecimal: ff
//     //  printf("Hexadecimal: %X\n", num); // Output: Hexadecimal: FF
//     ft_puthex_fd(num);
//     printf("Hexadecimal: %s\n", num);
//     return 0;
// }
int main()
{
    unsigned int decimal = 0xA05;

    // Print in lowercase hexadecimal
    // write(1, "Lowercase Hexadecimal: ", 23);
    ft_puthex_fd(decimal, 'x');
    write(1, "\n", 1);

    // Print in uppercase hexadecimal
    // write(1, "Uppercase Hexadecimal: ", 23);
    ft_puthex_fd(decimal, 'X');
    write(1, "\n", 1);

    return 0;
}