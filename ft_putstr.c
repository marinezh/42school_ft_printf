/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:38:11 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/04 23:25:38 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
    int len;
    len = 0;
	if(!str)
		return (write(1, "null", 6));
    while (str[len])
        len++;
    return (write(1, str, len));
}
// #include "stdio.h"

// int main()
// {
// 	int count = ft_putstr("hei");
// 	printf("count %d\n", count);
// }