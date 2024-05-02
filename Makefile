NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/pipex.c
		
OBJS = $(SRC:.c=.o)

OBJ_DIR = obj

RM = rm -f

INCLUDE = -L ./libft -lft 

LIB_DIR = libft/

#COLORS
GREEN=\033[0;32m
CIAN=\033[36m
RED=\033[31m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "${CIAN}Compiling...${NC}"
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "${GREEN}Program compiled✅${NC}"

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)
	@echo "${MAGENTA}All clean✨${NC}"

re:	fclean all

.PHONY: all clean fclean re