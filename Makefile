CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -L./libft/srcs/printf

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

#Object files for solong
SOURCES = $(wildcard srcs/*.c)

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
