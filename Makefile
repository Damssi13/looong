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
		empty_all.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(MLXFLAGS) -o $@


# %.o: %.c
# 	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re