/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:38 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/02 16:35:49 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	allocate_map(char *av, t_game *data)
{
	int		fd;
	int		i;
	char	*tmp;

	data->map = malloc(sizeof(char *) * (data->map_x + 1));
	if (!data->map)
		return ;
	fd = open(av, O_RDONLY);
	i = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		data->map[i++] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	data->map[data->map_x] = NULL;
	close(fd);
}

void	duplicate_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	data->map2 = malloc(sizeof(char *) * (data->map_x + 1));
	if (!data->map2)
		return ;
	while (data->map[i])
		data->map2[i++] = malloc(sizeof(char) * data->map_y + 1);
	j = 0;
	while (data->map[j])
	{
		ft_strlcpy(data->map2[j], data->map[j], data->map_y);
		j++;
	}
	data->map2[j] = NULL;
}
