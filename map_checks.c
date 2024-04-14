#include "long.h"


void    map_checks(t_game *data)
{
    check_rectangle(data);
    check_walls(data);
    check_characters(data);
    if(data->p_count != 1 || data->e_count != 1 || data->c_count == 0)
        erorr_mssg("Map elements are not valid !");
    elements_position(data);
}

void    check_rectangle(t_game *data)
{
    int i;
    int y;
    
    i = 0;
    y = data->map_y - 1;
    while(i < data->map_x - 1)
    {
        if(y == (ft_strlen(data->map[i]) - 1))
            i++;
        else if (y == ft_strlen(data->map[i]))
            erorr_mssg("Map is not rectangle !");
        else
            break;
    }
    if(y != ft_strlen(data->map[i]))
        erorr_mssg("Map is not rectangle !");
}

void    check_walls(t_game *data)
{
    int i;
    int j;
    
    j=0;
    while(j < data->map_y - 1)
    {
        if (data->map[0][j] != '1' || data->map[data->map_x - 1][j] != '1')
            erorr_mssg("Map is not surrounded by walls !");
        j++;
    }
    i=0;
    while (i < data->map_x)
    {
        if(data->map[i][0] != '1' || data->map[i][data->map_y - 2] != '1')
            erorr_mssg("Map is not surrounded by walls !");
        i++;
    }
}

void    elements_position(t_game *data)
{
    int i;
    int j;
   
    i=0;
    while(i < data->map_x)
    {
        j=0;
        while(j < data->map_y)
        {
            if(data->map[i][j] == 'P')
            {
                data->player_x = i;
                data->player_y = j;
                break;
            }
            j++;
        }
        i++;
    }
}

void    check_characters(t_game *data)
{
    int i;
    int j;

    i = 0;
    while(i < data->map_x)
    {
        j = 0;
        while(j < data->map_y - 1)
        { 
            if(data->map[i][j] == 'P')
                data->p_count++;
            else if (data->map[i][j] == 'C')
                data->c_count++;
            else if(data->map[i][j] == 'E')
                data->e_count++;
            else if(data->map[i][j] == '0')
                data->space_count++;
            else if (!ft_strchr("PCE01", data->map[i][j])) 
                erorr_mssg("Map elements are not valid !");
            j++;
        }
        i++;
    }
}

// int main()
// {
//     // c_data chars; 
//     // t_data data;
//     // char **map;

//     read_map(&data);
//     allocate_map(&data);
//     check_rectangle(&data);
//     // check_walls(&data, map);
//     // check_characters(&data, &chars, map);
//     // if(chars.p_count != 1 || chars.e_count != 1 || chars.c_count == 0)
//     // {
//     //     printf("Map elements are not valid");
//     //     exit(1);
//     // }
    
    
//     while(i < data.map_x)
//         printf("%s", map[i++]);
// }
