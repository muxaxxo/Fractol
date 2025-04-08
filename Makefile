NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

SRC = main.c events.c init.c mandel_manage.c render.c jul_manage.c cleaner.c
OBJ = $(SRC:.c=.o)

MLX = ./minilibx-linux/libmlx.a
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIB)
	@echo "Compilando $(NAME)..."
	@$(CC) $(OBJ) $(LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c fractol.h
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@echo "Compilando minilibx..."
	@$(MAKE) -C minilibx-linux

$(LIB):
	@echo "Compilando libft..."
	@$(MAKE) -C libft

clean:
	@echo "Eliminando archivos objeto..."
	@rm -f $(OBJ)
	@echo "Limpiando minilibx..."
	@$(MAKE) -C minilibx-linux clean
	@echo "Limpiando libft..."
	@$(MAKE) -C libft clean

fclean: clean
	@echo "Eliminando ejecutable..."
	@rm -f $(NAME)
	@echo "Limpiando libft..."
	@$(MAKE) -C libft fclean

re: fclean all

norm:
	@echo "Ejecutando norminette..."
	@find . -type f \( -name "*.c" -o -name "*.h" \) -not -path "./minilibx-linux/*" -exec norminette {} \;

.PHONY: all clean fclean re norm
