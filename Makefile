# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 11:03:58 by evlad             #+#    #+#              #
#    Updated: 2017/03/16 18:36:05 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printf.c \
		 main.c \
		 formating.c \
		 apply_flags.c \
		 apply_first_flags.c \
		 apply_first_flags_2.c \
		 apply_first_flags_3.c \
		 apply_first_flags_4.c \
		 apply_last_flags.c \
		 init_struct.c \
		 conv_1.c \
		 conv_2.c \
		 check_flags.c \

FLAGS = -g -Wextra -Werror -Wall 

NAME = printf

INC = header.h

OK = "	\033[1;32m[OK]\033[0m"

OBJ = $(CFILES:%.c=%.o)

#OBJ_PATH = ./obj/
#OBJ_FILE = $(CFILES:%.c=%.o)
#OBJ = $(OBJ_FILE:%=$(OBJ_PATH)%)

#$(OBJ_PATH)%.o: %.c $(INC)
#	@mkdir -p $(OBJ_PATH)
#	@gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME):
	@echo -n '-> Compilating'
#	@make -C ./libft/
	@echo -n '.'
	@gcc -c $(FLAGS) $(CFILES)
	@echo -n '.'
	@gcc -L ./libft/ -lft $(OBJ) -o $(NAME)
	@echo -n '.	'
	@echo $(OK)

clean:
	@echo -n '-> Deleting object files...'
	@/bin/rm -f $(OBJ)
	@make -C ./libft/ clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable file...'
	@/bin/rm -f $(NAME)
#	@make -C ./libft/ fclean
	@echo $(OK)

re: fclean all

.PHONY: all clean fclean re
