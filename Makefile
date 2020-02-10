#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 17:09:19 by tbratsla          #+#    #+#              #
#    Updated: 2020/01/29 17:09:20 by tbratsla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

SRC = 	ft_ls.c		\
		errors.c	\
		parse.c		\
		debug_func.c\
		sort.c		\
		free.c

SRC_DIR = srcs

OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

PRINTF = ./Libft/ft_printf/libftprintf.a

CC = gcc

H_DIR = -I inc

LIB = ./Libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(PRINTF) $(OBJS)
	@echo "Make ft_ls"
	@$(CC) $(FLAGS) $(OBJS) $(PRINTF) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< $(H_DIR)

$(LIB):
	@echo "Make Libft"
	@make -C ./Libft/

$(PRINTF):
	@echo "Make Printf"
	@make -C ./Libft/ft_printf/

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./Libft/ clean
	@make -C ./Libft/ft_printf/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./Libft/ fclean
	@make -C ./Libft/ft_printf/ fclean

re: fclean all

.PHONY:     re all clean fclean