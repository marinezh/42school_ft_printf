/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:34:19 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/04 00:23:51 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
// int main()
// {
//     ft_putnbr(1234);  // Output: 1234
//     ft_putchar('\n');
//     ft_putnbr(-5678); // Output: -5678
//     ft_putchar('\n');
//     ft_putnbr(0);     // Output: 0
//     ft_putchar('\n');
//     ft_putnbr(2147483647); // Output: -2147483648
// 	ft_putchar('\n');
// 	printf("%d",2147483647);
//     ft_putchar('\n');
//     return 0;
// }