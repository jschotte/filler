# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <jschotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 17:32:23 by jschotte          #+#    #+#              #
#    Updated: 2017/05/27 03:17:31 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   filler

SRC             =   main.c \
										parsing.c \
										play.c

INC             =   ./includes/filler.h
OBJ             =   $(addprefix $(OBJ_PATH),$(SRC:.c=.o))
CC              =   gcc
FLAGS           =   -Wall -Wextra -Werror
#FLAGS						=	#-fsanitize=thread
SRC_PATH        =   ./src/
INC_PATH        =   ./includes/
OBJ_PATH        =   ./obj/
LIB				=	libft/libft.a

all: $(NAME)

$(NAME): obj $(OBJ)
	@make -C libft/
	@$(CC) $(LIB) $(FLAGS) -o $(NAME)  $(OBJ)
	@printf "\n"
obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "✅ "

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all re clean fclean
