# NAMES
NAME = push_swap

# DIRECTORIES
LIBFT = ./libft/libft.a 
INC = include/
SRC_DIR = srcs/
OBJ_DIR = obj/

# COMPILER & FLAGS
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
INCFLAGS = -I$(INC)
RM = rm -f

# SOURCES FILES 
PARS_DIR = $(SRC_DIR)/parsing/handle_errors.c \

MAIN_DIR = $(SRC_DIR)/main/main.c \

# CONNECT ALL SOURCES FILES
SRCS = $(PARS_DIR) $(MAIN_DIR)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# RULES
start:
	@make all
	
$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

#COMPILE OBJ FROM SRCS
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re