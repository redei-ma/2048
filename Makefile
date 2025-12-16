NAME = 2048
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c movement.c print.c utils.c

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(SRC) game.h
	@echo "Compiling 2048..."
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -lncurses

clean:
	@echo "Cleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	@echo "Removing 2048 executable..."
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

.PHONY: all clean fclean re
.SILENT: