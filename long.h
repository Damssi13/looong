#ifndef LONG_H
#define LONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#define UP 65362
#define DOWN 65364
#define RIGHT 65363
#define LEFT 65361
#define A 97
#define W 119
#define S 115
#define D 100
#define Q 113
#define ESC 65307

#define WALL "./textures/wall.xpm"
#define AVATAR "./textures/avatar.xpm"
#define SPACE "./textures/space.xpm"
#define COINS "./textures/coin.xpm"
#define EXIT "./textures/exit.xpm"
#define A_RIGHT "./textures/sprites/right.xpm"
#define A_LEFT "./textures/sprites/left.xpm"
#define A_BACK "./textures/sprites/back.xpm"

#include <stdlib.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./minilibx-linux/mlx.h"

typedef struct s_game{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    **map;
    char    **map2;
    int     map_x;
    int     map_y;
    int     p_count;
    int     c_count;
    int     e_count;
    int     exit_x;
    int     exit_y;
    int     space_count;
    int     c_total;
    int     coins;
    int     player_steps;
    int     player_x;
    int     player_y;
}t_game;

char	*ft_strchr(char *s, int c);
int 	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void    read_map(char *av, t_game *data);
void    allocate_map(char *av, t_game *data);
void    duplicate_map(t_game *data);
void    check_rectangle(t_game *data);
void    erorr_mssg(char *str, t_game *data);
void    exit_mssg(char *str);
void    check_walls(t_game *data);
void    check_characters(t_game *data);
void    elements_position(t_game *data);
void    map_checks(t_game *data);
void    draw_map(t_game *data);
void    image_file(char c, t_game *data);
int     player_controle(int keycode, t_game *data);
int     move_player(int i, int y, char *img,t_game *data);
int     close_window(t_game *data);
void    empty_all(t_game *data);
void    checks_free(t_game *data);
void    path_check(t_game *data);
void    dup_map_free(t_game *data);
int     flood(int x, int y, char replacement, t_game *data);
int     game_control(int keycode, t_game *data);
void	check_name(char *name);
void    redraw_map(t_game *data, char *img);


// #include <X11/keysym.h>

#endif