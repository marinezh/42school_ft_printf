/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:27:19 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/03 21:39:53 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_puthex(unsigned int n, int lowercase);

int	ft_printf(const char *format, ...);

#endif