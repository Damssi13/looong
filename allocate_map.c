#include "long.h"

void    allocate_map(char *av,t_game *data)
{
    int fd;
    int i;
    char *tmp;
 
    data->map = malloc(sizeof(char *) * (data->map_x + 1));
    if(!data->map)
        return;
    fd = open(av, O_RDONLY);
    i = 0;
    while((tmp = get_next_line(fd)))
    {
        data->map[i++] = ft_strdup(tmp);
        free(tmp);     
    }
    data->map[data->map_x] = NULL;
    close(fd);
}

void    duplicate_map(t_game *data)
{
    int i;
    int j;

    i = 0;
    data->map2 = malloc(sizeof(char *) * (data->map_x + 1));
    if(!data->map2)
        return ;
    while(data->map[i])
        data->map2[i++] = malloc(sizeof(char) * data->map_y +1);
    j = 0;
    while(data->map[j])
    {
        ft_strcpy(data->map2[j], data->map[j]);
        j++;
    }
    data->map2[j] = NULL;
    // data->map2[data->map_x] = NULL;
}
