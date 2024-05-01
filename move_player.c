#include "long.h"


int    game_control(int keycode, t_game *data)
{
    if(keycode == ESC || keycode == Q)
        empty_all(data);
    else
        player_controle(keycode, data);
    return(0);
}

int     player_controle(int keycode, t_game *data)
{
    if (keycode == UP || keycode == W)
        move_player(-1, 0, A_BACK,data);
    else if(keycode == DOWN || keycode == S)
        move_player(1, 0, AVATAR, data);
    else if(keycode == RIGHT || keycode == D)
        move_player(0, 1, A_RIGHT, data);
    else if(keycode == LEFT || keycode == A)
        move_player(0, -1, A_LEFT,data);
    return(0);
}

int move_player(int i, int y, char *img,t_game *data)
{
    if(data->map[data->player_x + i][data->player_y + y] != '1' &&
     data->map[data->player_x + i][data->player_y + y] != 'E') //you can move if the next step is not a wall nor an exit
    {
        if(data->map[data->player_x + i][data->player_y + y] == 'C')//counting the eaten coins
            data->c_total++;
    
        data->map[data->player_x][data->player_y] = '0';
        data->player_x += i;
        data->player_y += y;
        data->player_steps++;
        ft_putnbr(data->player_steps);
        ft_putstr(" steps\n");
        data->map[data->player_x][data->player_y] = 'P';
    }
    else if(data->map[data->player_x + i][data->player_y + y] == 'E')
    {
        if(data->c_count == data->c_total)
            {
                ft_putnbr(data->player_steps + 1);
                ft_putstr(" steps\nYOU WIN\n");
                empty_all(data);
            }
    }
    redraw_map(data, img);
    return(0);
}

int     close_window(t_game *data)
{
    empty_all(data);
    return (0);
}