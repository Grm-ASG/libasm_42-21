# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 18:08:39 by imedgar           #+#    #+#              #
#    Updated: 2020/11/11 14:36:22 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRC			=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s

TEST_SRC	=	main.c

OBJ			=	$(SRC:.s=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)

AC			=	nasm
AFLAGS		=	-f elf64 -g
GCC			=	gcc
CFLAGS		=	-g -no-pie #-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.s
	$(AC) $(AFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ) test

fclean: clean
	$(RM) $(NAME) $(TEST_OBJ)

re: fclean all

test: test_compile
	./test | cat -e

test_compile: $(NAME) $(TEST_OBJ)
	$(GCC) $(CFLAGS) $(TEST_OBJ) -L. -lasm -o test

.PHONY: all clean fclean re run