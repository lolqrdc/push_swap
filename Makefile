# NAMES
NAME = push_swap

# DIRECTORIES
LIBFT = ./libft/libft.a 
INC = include/
OBJ_DIR = obj/
SRC_DIR = srcs/

# COMPILER & FLAGS
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
AR = ar rcs
RM = rm -f

# SOURCES FILES 
SRCS = $(SRC_DIR)parsing/handle_error.c \

# CONNECT ALL SOURCES FILES
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# RULES
start:
	@make all
	
$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean: 
				@$(RM) -r $(OBJ_DIR)
				@make clean -C ./libft

fclean: 		clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 			fclean all

.PHONY: start all clean fclean re