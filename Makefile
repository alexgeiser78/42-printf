# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 12:13:48 by ageiser           #+#    #+#              #
#    Updated: 2022/10/11 17:46:31 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

LIB = ar -rcs

INCLUDE = ft_printf.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $@ $?

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
