/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:01:28 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/02 16:34:43 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	read_map(char *av, t_game *data)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		exit_mssg("Unvalid !");
	data->map_y = ft_strlen(line);
	free(line);
	close(fd);
	fd = open(av, O_RDONLY);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	data->map_x = lines;
	close(fd);
}
