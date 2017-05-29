# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2017/05/27 03:22:23 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_abs.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strncpy.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_freejoin.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c gnl.c \
	  ft_printf.c \
	  ft_flags.c  \
	  ft_flags_2.c \
	  ft_conv.c \
	  conv_d.c \
	  conv_c.c \
	  conv_s.c \
	  conv_pourcent.c \
	  conv_u.c \
	  conv_x.c \
	  ft_itoa_base.c \
	  conv_o.c \
	  utils.c \
	  conv_p.c \
	  wrong_conv.c \
	  unicode.c \
	  conv_ws.c \
		ft_arraylen.c 


INC             =   ./includes/libft.h
OBJ             =   $(addprefix $(OBJ_PATH),$(SRC:.c=.o))
	CC              =   gcc
	FLAGS           =    -Wall -Wextra -Werror
	SRC_PATH        =   ./src/
	INC_PATH        =   ./includes/
	OBJ_PATH        =   ./obj/

all: $(NAME)

$(NAME):	obj $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@printf "☑️ "
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all re clean fclean
