/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:34:19 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/04 21:18:36 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putnbr(int nb)
{
    unsigned int nbr;
	int count;

	count = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nbr = nb * -1;
		count++;
    }
    else
        nbr = nb;
    if (nbr >= 10)
		 count += ft_putnbr(nbr / 10);
    count += ft_putchar(nbr % 10 + '0');

	return (count);
}
// int main()
// {
// 	int count = ft_putnbr(12345678);
// 	 ft_putchar('\n');
// 	printf("count %d\n", count);
//     ft_putnbr(1234);  // Output: 1234
//     ft_putchar('\n');
//     ft_putnbr(-5678); // Output: -5678
//     ft_putchar('\n');
//     ft_putnbr(0);     // Output: 0
//     ft_putchar('\n');
//     ft_putnbr(-2147483648); // Output: -2147483648
// 	ft_putchar('\n');
// 	printf("%ld",-2147483648);
//     ft_putchar('\n');
//     return 0;
// }