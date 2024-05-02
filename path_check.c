/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:17:47 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/02 16:48:38 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"
#include <string.h>

void	path_check(t_game *data)
{
	duplicate_map(data);
	data->coins = 0;
	if (flood(data->player_x, data->player_y, '2', data))
		return ;
	else
	{
		dup_map_free(data);
		erorr_mssg("The path is not valid !", data);
	}
	dup_map_free(data);
}

int	flood(int x, int y, char replacement, t_game *data)
{
	if (data->map2[x][y] == '1' || data->map2[x][y] == replacement
		|| data->map2[x][y] == 'E')
		return (0);
	if (data->map2[x][y] != '1')
	{
		if (data->map2[x][y] == 'C')
			data->coins++;
		data->map2[x][y] = replacement;
	}
	flood(x + 1, y, replacement, data);
	flood(x - 1, y, replacement, data);
	flood(x, y + 1, replacement, data);
	flood(x, y - 1, replacement, data);
	if (data->coins == data->c_count && (data->map2[data->exit_x
				- 1][data->exit_y] == '2' || data->map2[data->exit_x
			+ 1][data->exit_y] == '2' || data->map2[data->exit_x][data->exit_y
			+ 1] == '2' || data->map2[data->exit_x][data->exit_y - 1] == '2'))
		return (1);
	return (0);
}
