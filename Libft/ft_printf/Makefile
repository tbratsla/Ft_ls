#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 17:48:10 by tbratsla          #+#    #+#              #
#    Updated: 2020/01/29 17:48:12 by tbratsla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

inc = libftprintf.h

SRC = 	ft_printf.c				\
		ft_check_amount.c		\
		ft_get_params.c			\
		ft_long_itoa.c			\
		ft_print_param_c.c		\
		ft_print_param_d.c		\
		ft_print_param_s.c		\
		ft_print_u.c			\
		ft_strpjoin.c			\
		ft_unsigned_long_itoa.c	\
		help_to_print_x.c		\
		help_to_print_d.c		\
		help_to_print_i.c		\
		help_to_print_u.c		\
		help_to_print_ui.c		\
		ft_itoa_base.c			\
		ft_print_param_o.c		\
		help_to_print_o.c		\
		help_to_print_oi.c		\
		help_to_print_xi.c		\
		ft_print_param_x.c		\
		ft_print_param_p.c		\
		ft_atoi.c				\
		ft_bzero.c				\
		ft_isdigit.c			\
		ft_strnew.c				\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_isalpha.c			\
		ft_strncpy.c			\
		ft_strlen.c				\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_strchr.c				\
		ft_memalloc.c			\
		ft_itoa.c				\
		ft_genlenn.c			\
		ft_check.c				\
		ft_strdup.c				\
		ft_print_param_f.c		\
		ft_print_param_fi.c		\
		help_to_print_f.c		\
		help_to_print_fi.c		\
		ft_print_per.c			\
		help_to_norm_x.c		\
		help_to_norm_u.c		\
		help_to_norm_o.c		\
		help_to_norm_d.c		\
		help_to_norm_f.c 

SRC_DIR = srcs

OBJ_DIR = obj

H_DIR = -I inc

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(NAME):  $(OBJS)	
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< $(H_DIR)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re