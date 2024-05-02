/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:14:39 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/02 18:04:54 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	empty_all(t_game *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	dup_map_free(data);
}

void	checks_free(t_game *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	dup_map_free(t_game *data)
{
	int	i;

	i = 0;
	while (data->map2[i])
	{
		free(data->map2[i]);
		i++;
	}
	free(data->map2);
}

void	protect_img(t_game *data)
{
	if (data->img_ptr == NULL)
	{
		ft_putstr("Error:\nPicture is empty !");
		empty_all(data);
		exit(1);
	}
}
