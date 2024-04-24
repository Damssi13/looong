#include "long.h"

void    ft_image_file(char c, t_game *data)
{
    int i;
    i = 40;

    if(c == '1')
        data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &i,&i);
    else if (c == '0')
        data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, SPACE, &i,&i);
    else if(c == 'C')
        data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, COINS, &i,&i);
    else if(c == 'P')
        data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, AVATAR, &i,&i);
    else if(c == 'E')
        data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &i,&i);
}


void draw_map(t_game *data)
{
    int x;
    int y;

    x=0;
    while(x < data->map_x)
    {
        y=0;
        while(y < data->map_y - 1)
        {
            ft_image_file(data->map[x][y], data);
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, (y * 40), (x * 40));
            mlx_destroy_image(data->mlx_ptr, data->img_ptr);
            y++;
        }        
    x++;
    }
}   