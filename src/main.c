/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:46:30 by castorga          #+#    #+#             */
/*   Updated: 2023/11/26 15:46:32 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include "../include/window.h"
/*
cc main.c -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
*/

int	main(int ac, char *av[])
{
	t_game	game;
	t_win	win;

	if (ac == 2)
	{
		file_is_ber(av[1]);
		open_map(av[1], &game);
		create_map(game.map_fd, &game, av[1]);
		parsing_map(&game);
		win = set_game(&game);
		set_img(&game, 'w');
		//set_imgs(&win);
		//mlx_destroy_window(mlx_ptr, win_ptr);
		//mlx_destroy_display(mlx_ptr);

		mlx_loop(win.mlx);
		free(set_game);
	}
	else
		ft_errors(1);
	return (0);
}
