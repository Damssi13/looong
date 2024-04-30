#include "long.h"
void    empty_all(t_game *data)
{
    int i;

    i = 0;
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    
    while(data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    exit(0);
}

void    checks_free(t_game *data)
{
    int i;

    i = 0;
    while(data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    exit(0);
}
void    dup_map_free(t_game *data)
{
    int i;

    i = 0;
    while(data->map2[i])
    {
        free(data->map2[i]);
        i++;
    }
    free(data->map2);
}