/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:57:32 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/02 23:22:08 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>



int ft_puthex(unsigned int n, int lowercase)
{
    char *hex_digits;
    int count = 0;

    // Choose the appropriate set of hexadecimal digits based on 'lowercase'
    if (lowercase)
        hex_digits = "0123456789abcdef";  // Lowercase hexadecimal digits
    else
        hex_digits = "0123456789ABCDEF";  // Uppercase hexadecimal digits

    // Handle the special case when n is 0
    if (n == 0) {
        count += ft_putchar('0');
        return count;
    }

    // Start the conversion by printing the hexadecimal digits
    if (n >= 16)
        count =count + ft_puthex(n / 16, lowercase);  // Recursively process the higher order digits

    // Print the current digit
    count += ft_putchar(hex_digits[n % 16]);  // Print the remainder (lowest digit)

    return count;
}
int main() {
    unsigned int n = 3054;
    unsigned int n2 = 0xFF;
   // int count = ft_puthex(n, 0);  // 1 for lowercase
    int count2 = ft_puthex(n2, 0);  // 1 for lowercase
    //printf("\nTotal characters printed: %d\n", count);
    
    return 0;
}