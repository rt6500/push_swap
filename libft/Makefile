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

SRC_LIBFT = srcs/libft
SRC_PRINTF = srcs/printf

SRC_LIBFT_FILES = $(wildcard $(SRC_LIBFT)/*.c)
SRC_PRINTF_FILES = $(wildcard $(SRC_PRINTF)/*.c)

OBJS_LIBFT = $(patsubst $(SRC_LIBFT)/%.c,srcs/libft/objs/%.o,$(SRC_LIBFT_FILES))
OBJS_PRINTF = $(patsubst $(SRC_PRINTF)/%.c,srcs/printf/objs/%.o,$(SRC_PRINTF_FILES))

OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF)

AR = ar -rcs

RM = rm -f

# Explicit list of objs directories
OBJS_DIR_LIBFT = $(SRC_LIBFT)/objs
OBJS_DIR_PRINTF = $(SRC_PRINTF)/objs

# LIBFT = $(LIBFT_PATH)/libft.a
all : $(OBJS_DIR_LIBFT) $(OBJS_DIR_PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule for libft sources
$(SRC_LIBFT)/objs/%.o: $(SRC_LIBFT)/%.c | $(OBJS_DIR_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ -I./ -I. -I./srcs/printf

$(SRC_PRINTF)/objs/%.o: $(SRC_PRINTF)/%.c | $(OBJS_DIR_PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./srcs/printf

$(OBJS_DIR_LIBFT):
	mkdir -p $@

$(OBJS_DIR_PRINTF):
	mkdir -p $@

clean :
	$(RM) $(OBJS)
	find srcs/ -type f -name '*.o' -delete
	$(RM) -r $(OBJS_DIR_LIBFT)
	$(RM) -r $(OBJS_DIR_PRINTF)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
