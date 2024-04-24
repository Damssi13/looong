#include "long.h"

int     player_controle(int keycode, t_game *data)
{
    if (keycode == UP || keycode == W)
        move_player(-1, 0, data);
    else if(keycode == DOWN || keycode == S)
        move_player(1, 0, data);
    else if(keycode == RIGHT || keycode == D)
        move_player(0, 1, data);
    else if(keycode == LEFT || keycode == A)
        move_player(0, -1, data);
    return(0);
}

int move_player(int i, int y, t_game *data)
{
    if(data->map[data->player_x + i][data->player_y + y] != '1' &&
     data->map[data->player_x + i][data->player_y + y] != 'E')
    {
        if(data->map[data->player_x + i][data->player_y + y] == 'C')
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
    draw_map(data);
    return(0);
}
int     close_window(t_game *data)
{
    empty_all(data);
    return (0);
}