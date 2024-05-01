#include "long.h"
#include <string.h>
void    path_check(t_game *data)
{
    duplicate_map(data);
    data->coins = 0;
    if(flood(data->player_x, data->player_y,'2', data))
        return ;
    else
    {
        dup_map_free(data);
        erorr_mssg("The path is not valid !", data);
    }
    dup_map_free(data);
}

int    flood(int x, int y, char replacement, t_game *data)
{   

    if(data->map2[x][y] == '1' || data->map2[x][y] == replacement || data->map2[x][y] == 'E')
        return (0);
    if(data->map2[x][y] != '1')//you paint the empty space
    {
        if(data->map2[x][y] == 'C')
            data->coins++;
        data->map2[x][y] = replacement;
    }
    //recursive floodfill        
    flood(x+1,y,replacement,data);
    flood(x-1,y,replacement,data);
    flood(x,y+1,replacement,data);
    flood(x,y-1,replacement,data);
    if(data->coins == data->c_count && (data->map2[data->exit_x -1][data->exit_y] == '2'
        || data->map2[data->exit_x +1][data->exit_y] == '2' 
        || data->map2[data->exit_x][data->exit_y +1] == '2' 
        || data->map2[data->exit_x][data->exit_y -1] == '2'))
        return(1);
    return(0);
}
// int main()
// {
//     t_game data;
//         int y = 0;
//     char **map;

//     map = (char **)malloc(sizeof(char *) * 4);
//     if(!map)
//         return 1;
//     while(y < 5)
//     {
//       map[y] = (char *)malloc(sizeof(char) * 7);
//       y++;
//     }
    
//     strcpy(map[0], "111111");
//     // strcpy(map[1], "1C00E1");
//     // strcpy(map[2], "10C001");
//     strcpy(map[1], "1PC01");
//     strcpy(map[2], "111111");
//     map[3] = NULL;

//     // if(!flood(3,1,'2',&data))
//     //     printf("valid");
//     // else
//     //     printf("unvalid");
//     for(int i = 0;i<3;i++){
//         printf("%s",map[i]);
//         printf("\n");
//     }
// }