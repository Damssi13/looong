#include "long.h"

void    read_map(char *av,t_game *data)
{
    int fd;
    int lines;
    char *line;
    
    fd = open(av, O_RDONLY);
    line = get_next_line(fd);
    data->map_y = ft_strlen(line);
    free(line);
    close(fd);
    fd = open(av, O_RDONLY);
    lines = 0;
    while((line = get_next_line(fd)))
    {
        lines++;
        free(line);
    }
    data->map_x = lines;
    close(fd);
    data->c_count = 0;
    data->e_count = 0;
    data->p_count = 0;
    data->space_count = 0;
}

// int main()
// {
//     t_game data;
//     read_map(&data);
//     printf("x-->%d\n", data.x);
//     printf("y-->%d", data.y);
// }