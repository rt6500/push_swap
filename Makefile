# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 15:59:14 by rseki             #+#    #+#              #
#    Updated: 2025/04/26 15:59:16 by rseki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -L./libft/srcs/printf

OBJDIR = objs

NAME = push_swap

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

EXEC = $(NAME)

SOURCES = srcs/binary_radix_sort.c \
srcs/ft_atoi_ps.c srcs/operations_rotate.c \
srcs/sort_five.c srcs/built_stack.c srcs/main.c srcs/operations_swap.c \
srcs/sort_utilis.c srcs/operations_push.c srcs/operation_swap_utilis.c \
srcs/operations_rev_rotate.c  srcs/sort_few.c srcs/validate_input.c \
srcs/validate_input_utilis.c

OBJECTS = $(patsubst srcs/%.c, $(OBJDIR)/%.o, $(SOURCES))

$(info OBJECTS = $(OBJECTS))

AR = ar -rcs

RM = rm -f

all : $(LIBFT) $(EXEC)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(CFLAGS) $(LDFLAGS) $(LIBFT)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./include -I $(LIBFT_PATH)/include

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJECTS)
	$(RM) -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(EXEC) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re libft
