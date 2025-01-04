/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:22:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/04 01:31:30 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_put_unsigned(unsigned int n)
{
	int count;

	count = 0;
	
	if (n >= 10)
		 count += ft_put_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');

	return (count);
}

// int main()
// {
// 	unsigned int n = 4252;
// 	int result;
// 	result = ft_put_unsigned(n);
// 	ft_putchar('\n');
// 	printf("result: %d\n", result);
// 	ft_putchar('\n');
// 	//ft_put_unsigned(n);
// 	printf("originl printf: %u", n);
// }