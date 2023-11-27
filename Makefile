NAME = so_long

LIBFT_DIR = libft/
PRINTF_DIR = libft/ft_printf/
MLX_DIR = mlx/

LIBFT_FILE = libft.a
PRINTF_FILE = libftprintf.a

MLX_FILE = libmlx.a

LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_FILE)) 
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

SRCS_DIR = src/
SRC_FILES =	 main.c checks.c load_map.c utils_1.c

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS        := $(OBJS:.o=.d)
CC = clang -g
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
AR = ar rc
#INCLUDE = -I include/ -I libft/ -I mlx/ -I 
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(PRINTF_DIR)

all: 		$(NAME)

subsystems:
			@make -C $(LIBFT_DIR)
			@make -C $(MLX_DIR)
			@make -C $(PRINTF_DIR)

$(NAME):	subsystems $(OBJS_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -L$(PRINTF_DIR) -libftprintf $(MLXFLAGS) -o $@

$(OBJS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS) $(DEPS)


fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all
-include $(DEPS)			

.PHONY: all clean fclean re subsystems
