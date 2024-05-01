NAME = long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L minilibx-linux -lmlx -lX11 -lXext 
SRCS = 	get_next_line.c \
		get_next_line_utils.c \
		game.c \
		read_map.c\
		allocate_map.c\
		map_checks.c\
		erorr_mssg.c\
		draw_map.c\
		move_player.c\
		empty_all.c\
		path_check.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)       
	$(CC) $(CFLAGS) $^ $(MLXFLAGS) -o $@

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR) 

re: fclean all

.PHONY: all clean fclean re