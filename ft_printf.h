/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:27:19 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/01/04 21:08:10 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h> // DELETE THIS

int	ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int nb);
int ft_puthex(unsigned int n, int lowercase);
int	ft_put_unsigned(unsigned int n);
int ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif