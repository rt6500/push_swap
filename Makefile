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
LDFLAGS = -L./libft -L./libft/srcs/printf -L./libft/srcs/gnl

#Directory for OBJECTS
OBJDIR = objs

#Define the final excutable name
NAME = push_swap

#Path to libft
LIBFT_PATH = ./libft

#Link to the libft static library
LIBFT = $(LIBFT_PATH)/libft.a

#The output of the executable
EXEC = $(NAME)

#Object files
SOURCES = srcs/binary_radix_sort.c srcs/ft_atoi_ps.c srcs/operations_rotate.c \
srcs/sort_five.c srcs/built_stack.c srcs/main.c srcs/operations_swap.c \
srcs/sort_utilis.c srcs/operations_push.c srcs/operation_swap_utilis.c \
srcs/operations_rev_rotate.c  srcs/sort_few.c srcs/validate_input.c

#Store object files in objs
OBJECTS = $(patsubst srcs/%.c, $(OBJDIR)/%.o, $(SOURCES))

$(info OBJECTS = $(OBJECTS))

# Static library archiving command
AR = ar -rcs

# Clean-up command
RM = rm -f

# All target: compile libft first and then the solong project
all : $(LIBFT) $(EXEC)

#Compile the libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

#Compile the solong excutable
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
