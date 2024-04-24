#include "long.h"

void allocate_map(char *av,t_game *data)
{
    int fd;
    int i;
    char *tmp;
 
    data->map = malloc(sizeof(char *) * (data->map_x + 1));
    if(!data->map)
        return;
    fd = open(av, O_RDONLY);
    i=0;
    while((tmp = get_next_line(fd)))
    {
        data->map[i++] = ft_strdup(tmp);
        free(tmp);     
    }
    data->map[data->map_x] = NULL;
    close(fd);
}