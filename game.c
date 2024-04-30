#include "long.h"
#include "./minilibx-linux/mlx.h"
     

int    game_control(int keycode, t_game *data)
{
    if(keycode == ESC)
        empty_all(data);
    else
        player_controle(keycode, data);
    return(0);
}


int main(int ac, char **av)
{
    t_game data;

    if(ac != 2)
        exit_mssg("Arguments problem !");
    read_map(av[1], &data);
    allocate_map(av[1], &data);
    map_checks(&data); //checks
    // duplicate_map(&data);
    path_check(&data);

    // for(int i = 0; i < 4;i++)
    //     printf("%s", data.map2[i]);

    data.mlx_ptr = mlx_init();
    // if(!data.mlx_ptr)
    //     erorr_mssg("Failed", &data);

    data.win_ptr = mlx_new_window(data.mlx_ptr, (40 * (data.map_y -1)), (40 * data.map_x), "GTA");
    draw_map(&data);
    mlx_key_hook(data.win_ptr, game_control, &data); //for moving and ESC close
    mlx_hook(data.win_ptr,17,0,close_window,&data); //for cross close
    mlx_loop(data.mlx_ptr);    
    return 0;
}           
