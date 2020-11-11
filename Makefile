# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 18:08:39 by imedgar           #+#    #+#              #
#    Updated: 2020/11/11 21:57:51 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRC			=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s	\
				ft_strdup.s

SRC_BONUS	=	ft_list_size_bonus.s

SRC_TEST	=	main.c

DIR_SRC		=	srcs/
DIR_SRCBNS	=	bonus/
DIR_OBJ		=	obj/
DIR_INC		=	includes/

OBJ			=	$(addprefix $(DIR_OBJ),$(SRC:.s=.o))
OBJ_BNS		=	$(addprefix $(DIR_SRCBNS),$(SRC_BONUS:.s=.o))
OBJ_TEST	=	$(SRC_TEST:.c=.o)

AS			=	nasm
ASFLAGS		=	-gdwarf -f elf64 -I $(DIR_INC)
GCC			=	gcc
CFLAGS		=	-g -no-pie -I $(DIR_INC)#-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs

ifeq ($(BONUS), YES)
REQ			=	make_dir $(OBJ) $(OBJ_BNS)
OBJ_FILES	=	$(OBJ) $(OBJ_BNS)
else
REQ			=	make_dir $(OBJ)
OBJ_FILES	=	$(OBJ)
endif

all: $(NAME)

$(NAME): $(REQ)
	$(AR) $@ $(OBJ_FILES)

$(DIR_OBJ)%.o: $(DIR_SRC)%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(DIR_SRCBNS)%.o: $(SRC_BONUS)%.s
	$(AS) $(ASFLAGS) -o $@ $<

make_dir:
	mkdir -p $(DIR_OBJ)

clean:
	$(RM) $(OBJ) test
	$(RM) -r $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ_TEST)

re: fclean all

bonus:
	$(MAKE) BONUS="YES" all --no-print-directory

test: test_compile
	./test | cat -e

test_compile: $(NAME) $(OBJ_TEST)
	$(GCC) $(CFLAGS) $(OBJ_TEST) -o test -L. -lasm

.PHONY: all clean fclean re run test_compile test make_dir bonus
.SILENT: bonus