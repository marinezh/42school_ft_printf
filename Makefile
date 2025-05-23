# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 14:19:08 by mzhivoto          #+#    #+#              #
#    Updated: 2025/01/07 14:22:23 by mzhivoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Source files and object files
SRC = ft_printf.c\
	ft_putchar.c\
	ft_puthex.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_put_unsigned.c\
	ft_putptr.c


OBJ = $(SRC:.c=.o)

# Default rule to create the library
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ)
	ar rcs $@ $^

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the library
clean:
	rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o ftprintf.so $(OBJ)
	
.PHONY: all clean fclean re
