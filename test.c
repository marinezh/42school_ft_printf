/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2024/12/18 14:36:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int ft_putchar(char c)
{
    write(1, &c, 1);
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

int ft_putstr(char *str)
{
    int len;
    len = 0;
    while (str[len])
    {
        len++;
    }
    write(1, str, len);
    return (len);
}

int main(void)
{
    char *s = "hello";
    char k = 'c';
    int num = 42;
    int len = ft_putstr(s);
    printf("len %d\n", len);
    // ft_putstr("hello\n");
    // ft_putstr("hi\n");
    // ft_putnbr(num);
    // ft_putchar('\n');
    // ft_putchar(k);
    // ft_putchar('\n');
    return (0);
}