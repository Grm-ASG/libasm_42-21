# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 18:08:39 by imedgar           #+#    #+#              #
#    Updated: 2020/11/12 14:46:37 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRC			=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s	\
				ft_strdup.s

SRC_BNS		=	ft_list_size_bonus.s		\
				ft_list_push_front_bonus.s

SRC_TEST	=	main.c

DIR_SRC		=	srcs/
DIR_SRCBNS	=	bns/
DIR_OBJ		=	obj/
DIR_INC		=	includes/

OBJ			=	$(addprefix $(DIR_OBJ),$(SRC:.s=.o))
OBJ_TEST	=	$(SRC_TEST:.c=.o)

AS			=	nasm
ASFLAGS		=	-gdwarf -f elf64 -I $(DIR_INC)
GCC			=	gcc
CFLAGS		=	-g -no-pie  -I $(DIR_INC) #-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs

ifeq ($(BONUS), YES)
SRC			+= $(SRC_BNS)
CFLAGS		+= -D BONUS_PART
endif

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJ)
	$(AR) $@ $(OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(DIR_OBJ)%_bonus.o: $(DIR_SRCBNS)%_bonus.s
	$(AS) $(ASFLAGS) -o $@ $<

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

clean:
	$(RM) -r $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ_TEST) test

re: fclean all

bonus:
	$(MAKE) BONUS="YES" all --no-print-directory
	
test: fclean test_compile
	./test | cat -e

test_compile: $(NAME) $(OBJ_TEST)
	$(GCC) $(CFLAGS) $(OBJ_TEST) -o test -L. -lasm

test_bonus:
	$(MAKE) BONUS="YES" test --no-print-directory

.PHONY: all clean fclean re run test_compile test bonus test_bonus
.SILENT: bonus