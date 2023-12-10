/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:13:32 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 12:13:34 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include "../include/window.h"

/*Funcion que inicializa minilibx, crea una ventana y set imgs*/
t_win	set_game(t_game *game)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		ft_errors2(5);
	return ((t_win){mlx,
		mlx_new_window(mlx, game->w * IMG_PX, game->h * IMG_PX, "so_long"),
		game->w, game->h, {
			mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", \
			&game->w, &game->h),
			mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", \
			&game->w, &game->h),
			mlx_xpm_file_to_image(mlx, "./textures/cols.xpm", \
			&game->w, &game->h),
			mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", \
			&game->w, &game->h),
			mlx_xpm_file_to_image(mlx, "./textures/open.xpm", \
			&game->w, &game->h),
			{
				mlx_xpm_file_to_image(mlx, "./textures/player_up.xpm", \
				&game->w, &game->h),
				mlx_xpm_file_to_image(mlx, "./textures/player_right.xpm", \
				&game->w, &game->h),
				mlx_xpm_file_to_image(mlx, "./textures/player_down.xpm", \
				&game->w, &game->h),
				mlx_xpm_file_to_image(mlx, "./textures/player_left.xpm", \
				&game->w, &game->h)
			},
			game->w, game->h
		}
	});
}

void	set_player(t_game *game, int w, int h, char dir)
{
	t_win	win;

	if (dir == 'w')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				win.imgs.player.player_up, w * 32, h * 32);
	if (dir == 'a')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				win.imgs.player.player_left, w * 32, h * 32);
	if (dir == 's')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				win.imgs.player.player_down, w * 32, h * 32);
	if (dir == 'd')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				win.imgs.player.player_right, w * 32, h * 32);
}

void	set_img(t_game *g, char dir)
{
	int		h;
	int		w;
	t_win	win;

	h = -1;
	while (++h < g->h)
	{
		w = -1;
		while (++w < g->w)
		{
			if (g->matrix[h * g->w + w][g->h] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, win.imgs.wall, w * 32, h * 32);
			else if (g->matrix[h * g->w + w][g->h] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, win.imgs.cols, w * 32, h * 32);
			else if (g->matrix[h * g->w + w][g->h] == 'P')
				set_player(g, w, h, dir);
			else if (g->matrix[h * g->w + w][g->h] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, win.imgs.exit, w * 32, h * 32);
			else
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, win.imgs.floor, w * 32, h * 32);
		}
	}
}

