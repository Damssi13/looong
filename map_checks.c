#include "long.h"


void    map_checks(t_game *data)
{
    check_rectangle(data);
    check_walls(data);
    check_characters(data);
    if(data->p_count != 1 || data->e_count != 1 || data->c_count == 0)
        erorr_mssg("Map elements are not valid !", data);
    elements_position(data);
    path_check(data);
    // Just for initializing !
    data->c_total = 0;
    data->player_steps = 0;
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
            erorr_mssg("Map is not rectangle !", data);
        else
            break;
    }
    if(y != ft_strlen(data->map[i]))
        erorr_mssg("Map is not rectangle !", data);
}

void    check_walls(t_game *data)
{
    int i;
    
    i = 0;
    while(i < data->map_y - 1)
    {
        if (data->map[0][i] != '1' || data->map[data->map_x - 1][i] != '1')
            erorr_mssg("Map is not surrounded by walls !", data);
        i++;
    }
    i=0;
    while (i < data->map_x)
    {
        if(data->map[i][0] != '1' || data->map[i][data->map_y - 2] != '1')
            erorr_mssg("Map is not surrounded by walls !", data);
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
            }
            if(data->map[i][j] == 'E')
            {
                data->exit_x = i;
                data->exit_y = j;
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
                erorr_mssg("Map elements are not valid !", data);
            j++;
        }
        i++;
    }
}
