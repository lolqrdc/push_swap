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
INS_DIR = $(SRC_DIR)/instructions/push.c \
			$(SRC_DIR)/instructions/swap.c \
			$(SRC_DIR)/instructions/reverse.c \
			$(SRC_DIR)/instructions/rotate.c \

PARS_DIR = $(SRC_DIR)/parsing/handle_errors.c \
			
BUILD_DIR = $(SRC_DIR)/stack/build_stack.c \

ALGO_DIR = $(SRC_DIR)/algorithms/low_nbr_algo.c \

MAIN_DIR = $(SRC_DIR)main.c \

# CONNECT ALL SOURCES FILES
SRCS = $(INS_DIR) $(PARS_DIR) $(MAIN_DIR) $(BUILD_DIR) $(ALGO_DIR)
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