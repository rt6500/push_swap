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
CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

SRC_LIBFT_PATH = srcs/libft
SRC_PRINTF_PATH = srcs/printf
SRC_GNL_PATH = srcs/gnl

SRC_LIBFT_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_itoa_base.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c \
ft_lstiter.c ft_free_char_array.c ft_free_array_v.c

SRC_PRINTF_FILES = ft_printf.c ft_char_fmt.c ft_string_fmt.c \
ft_pointer_fmt.c ft_decimal_fmt.c ft_unsigned_decimal_fmt.c \
ft_hexadecimal_fmt.c ft_uppercase_hexadecimal_fmt.c ft_percent_fmt.c

SRC_GNL_FILES = get_next_line.c get_next_line_utils.c \
get_next_line_bonus.c get_next_line_utils_bonus.c

SRC_LIBFT = $(addprefix $(SRC_LIBFT_PATH)/, $(SRC_LIBFT_FILES))
SRC_PRINTF = $(addprefix $(SRC_PRINTF_PATH)/, $(SRC_PRINTF_FILES))
SRC_GNL = $(addprefix $(SRC_GNL_PATH)/, $(SRC_GNL_FILES))

OBJS_LIBFT = \
$(patsubst $(SRC_LIBFT_PATH)/%.c, $(SRC_LIBFT_PATH)/objs/%.o,$(SRC_LIBFT))
OBJS_PRINTF = \
$(patsubst $(SRC_PRINTF_PATH)/%.c, $(SRC_PRINTF_PATH)/objs/%.o,$(SRC_PRINTF))
OBJS_GNL = $(patsubst $(SRC_GNL_PATH)/%.c, $(SRC_GNL_PATH)/objs/%.o,$(SRC_GNL))

OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)

AR = ar -rcs

RM = rm -f

DIRS = $(SRC_LIBFT_PATH)/objs $(SRC_PRINTF_PATH)/objs $(SRC_GNL_PATH)/objs

# LIBFT = $(LIBFT_PATH)/libft.a
all : $(DIRS) $(NAME)

$(DIRS) :
	@mkdir -p $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule for libft sources
$(SRC_LIBFT_PATH)/objs/%.o: $(SRC_LIBFT_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I./

$(SRC_PRINTF_PATH)/objs/%.o: $(SRC_PRINTF_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./srcs/printf

$(SRC_GNL_PATH)/objs/%.o: $(SRC_GNL_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I./srcs/gnl

clean :
	$(RM) $(OBJS)
	@rm -rf $(DIRS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
