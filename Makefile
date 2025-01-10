NAME = so_long
BONUS_NAME = so_long_bonus

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

LIBMLX = ../minilibx-linux/libmlx_Linux.a

CC = cc 
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L../minilibx-linux -lmlx -lX11 -lXext -lm
REMOVE = rm -f

SRCS = srcs/so_long.c srcs/ft_check_map.c srcs/ft_close_game.c srcs/ft_free_memory.c \
		srcs/ft_handle_input.c srcs/ft_init_game.c srcs/ft_init_map.c srcs/ft_path_checker.c \
		srcs/ft_render_map.c srcs/ft_utils.c utils/ft_calloc.c utils/ft_printf.c utils/ft_split.c \
		utils/ft_strchr.c utils/ft_strdup.c utils/ft_strlcpy.c utils/ft_strlcat.c utils/ft_strlen.c \
		utils/ft_strnstr.c utils/get_next_line.c utils/ft_putchar_fd.c utils/ft_puthex.c utils/ft_putnbr_fd.c \
		utils/ft_putptr.c utils/ft_putstr_fd.c utils/ft_putunint_fd.c utils/ft_bzero.c utils/ft_strjoin.c \
		utils/ft_memset.c

BONUS_SRCS = srcs_bonus/so_long_bonus.c srcs_bonus/ft_check_map_bonus.c \
			srcs_bonus/ft_close_game_bonus.c srcs_bonus/ft_free_memory_bonus.c \
			srcs_bonus/ft_handle_input_bonus.c srcs_bonus/ft_init_game_bonus.c \
			srcs_bonus/ft_init_map_bonus.c srcs_bonus/ft_path_checker_bonus.c \
			srcs_bonus/ft_render_map_bonus.c srcs_bonus/ft_utils_bonus.c \
			utils/ft_calloc.c utils/ft_printf.c utils/ft_split.c utils/ft_strchr.c \
			utils/ft_strdup.c utils/ft_strlcpy.c utils/ft_strlcat.c utils/ft_strlen.c \
			utils/ft_strnstr.c utils/get_next_line.c utils/ft_itoa.c utils/ft_putchar_fd.c \
			utils/ft_puthex.c utils/ft_putnbr_fd.c utils/ft_putptr.c utils/ft_putstr_fd.c \
			utils/ft_putunint_fd.c utils/ft_bzero.c utils/ft_strjoin.c utils/ft_memset.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER = srcs/includes/so_long.h 
BONUS_HEADER = srcs_bonus/includes_bonus/so_long_bonus.h
UTILS_HEADER = utils/utils.h 

all: $(NAME)

%.o: %.c $(HEADER) $(UTILS_HEADER)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBMLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)\n"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_HEADER) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBMLX) $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) was compiled with bonus.$(RESET)\n"

clean: 
	@$(REMOVE) $(OBJS) $(BONUS_OBJS)
	@echo "$(NAME): $(RED)Object files were deleted.$(RESET)"

fclean: clean
	@$(REMOVE) $(NAME) $(BONUS_NAME)
	@echo "$(NAME): $(RED)$(NAME) and $(BONUS_NAME) were deleted.$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re