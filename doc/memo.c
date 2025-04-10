CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC_LIBFT = srcs/libft
SRC_PRINTF = srcs/printf
SRC_GNL = srcs/gnl

SRC_LIBFT_FILES = $(wildcard $(SRC_LIBFT)/*.c)
SRC_PRINTF_FILES = $(wildcard $(SRC_PRINTF)/*.c)
SRC_GNL_FILES = $(wildcard $(SRC_GNL)/*.c)

OBJS_LIBFT = $(patsubst $(SRC_LIBFT)/%.c,srcs/libft/objs/%.o,$(SRC_LIBFT_FILES))
OBJS_PRINTF = $(patsubst $(SRC_PRINTF)/%.c,srcs/printf/objs/%.o,$(SRC_PRINTF_FILES))
OBJS_GNL = $(patsubst $(SRC_GNL)/%.c, $(SRC_GNL)/objs/%.o,$(SRC_GNL_FILES))

OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)

AR = ar -rcs

RM = rm -f

# Explicit list of objs directories
OBJS_DIR_LIBFT = $(SRC_LIBFT)/objs
OBJS_DIR_PRINTF = $(SRC_PRINTF)/objs
OBJS_DIR_GNL = $(SRC_GNL)/objs

# LIBFT = $(LIBFT_PATH)/libft.a
all : $(OBJS_DIR_LIBFT) $(OBJS_DIR_PRINTF) $(OBJS_DIR_GNL) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule for libft sources
$(SRC_LIBFT)/objs/%.o: $(SRC_LIBFT)/%.c | $(OBJS_DIR_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./srcs/printf -I./srcs/gnl

$(SRC_PRINTF)/objs/%.o: $(SRC_PRINTF)/%.c | $(OBJS_DIR_PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./srcs/printf -I./srcs/gnl

$(SRC_GNL)/objs/%.o: $(SRC_GNL)/%.c | $(OBJS_DIR_GNL)
	$(CC) $(CFLAGS) -c $< -o $@ -I./srcs/gnl

$(OBJS_DIR_LIBFT):
	mkdir -p $@

$(OBJS_DIR_PRINTF):
	mkdir -p $@

$(OBJS_DIR_GNL):
	mkdir -p $@

clean :
	$(RM) $(OBJS)
	find srcs/ -type f -name '*.o' -delete
	$(RM) -r $(OBJS_DIR_LIBFT)
	$(RM) -r $(OBJS_DIR_PRINTF)
	$(RM) -r $(OBJS_DIR_GNL)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re libft