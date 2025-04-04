# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rseki <rseki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 19:12:18 by rseki             #+#    #+#              #
#    Updated: 2024/08/03 15:26:08 by rseki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

LIBFT_PATH = ./srcs/libft
PRINTF_PATH = ./srcs/printf
GNL_PATH = ./srcs/gnl

LIBFT = $(LIBFT_PATH)/libft.a

AR = ar -rcs

RM = rm -f

SOURCES =	$(wildcard $(LIBFT_PATH)/*c) \
			$(wildcard $(PRINTF_PATH)/*c) \
			$(wildcard $(GNL_PATH)/*.c)

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./ -I $(LIBFT_PATH) -I $(PRINTF_PATH) -I $(GNL_PATH)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
