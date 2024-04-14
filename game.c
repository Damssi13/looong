#include <stdio.h>          
#include <stdlib.h>
#include "long.h"
#include "./minilibx-linux/mlx.h"

int    move_player(int keycode, t_game *data)
{
    (void)data;

    if(keycode = RIGHT)
        

    if (keycode == ESC)
        exit(0);
    
    return(0);
}


int main()
{
    t_game data;


    read_map(&data);
    allocate_map(&data);
    //checks
    map_checks(&data);

    data.mlx_ptr = mlx_init();
    if(data.mlx_ptr == NULL)
        erorr_mssg("failed");

    data.win_ptr = mlx_new_window(data.mlx_ptr, (40 * (data.map_y -1)), (40 * data.map_x), "GTA");

    draw_map(&data);
    // mlx_destroy_window(data.mlx_ptr, data.win_ptr); 

    //event for closing
    mlx_key_hook(data.win_ptr, move_player, &data);


       
    mlx_loop(data.mlx_ptr);
    
    //it does nothing.
    //free(data.mlx_ptr);
    
    return 0;


}           
