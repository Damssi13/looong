/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:33 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/02 16:52:22 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		exit_mssg("Arguments problem !");
	check_name(av[1]);
	data.c_count = 0;
	data.e_count = 0;
	data.p_count = 0;
	data.space_count = 0;
	read_map(av[1], &data);
	allocate_map(av[1], &data);
	map_parsing(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (40 * (data.map_y - 1)), (40
				* data.map_x), "GTA");
	draw_map(&data);
	mlx_key_hook(data.win_ptr, game_control, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
