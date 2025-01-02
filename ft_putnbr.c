/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:34:19 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/02 23:35:02 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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