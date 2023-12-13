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

// function that you want to call evety time you exit the game
/*int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}*/

/*Funcion que inicializa valores*/
void	set_values(t_game *g)
{
	g->collected = 0;
	g->walk_cnt = 0;
	g->h = 0;
	g->w = 0;
}

/*Funcion que setea las imgs*/
void	set_images(t_game *g)
{
	g->imgs.wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.floor = mlx_xpm_file_to_image(g->mlx, "./textures/open.xpm",&(g->imgs.w), &(g->imgs.h));
	g->imgs.coll = mlx_xpm_file_to_image(g->mlx, "./textures/coll.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.exit = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.open = mlx_xpm_file_to_image(g->mlx, "./textures/open.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.player.player_up = mlx_xpm_file_to_image(g->mlx, "./textures/player_up.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.player.player_right = mlx_xpm_file_to_image(g->mlx, "./textures/player_right.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.player.player_down = mlx_xpm_file_to_image(g->mlx, "./textures/player_down.xpm", &(g->imgs.w), &(g->imgs.h));
	g->imgs.player.player_left = mlx_xpm_file_to_image(g->mlx, "./textures/player_left.xpm", &(g->imgs.w), &(g->imgs.h));
	set_images_to_win(g, 'w');
}

void	set_player(t_game *g, int y, int x, char dir)
{
	if (dir == 'w')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_up, y * 32, x * 32);
	if (dir == 'a')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_left, y * 32, x * 32);
	if (dir == 's')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_down, y * 32, x * 32);
	if (dir == 'd')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_right, y * 32, x * 32);
}

void	set_images_to_win(t_game *g, char dir)
{
	int		y;
	int		x;

	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			if (g->matrix[y][x] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.wall, x * 32, y * 32);

			else if (g->matrix[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.coll, x * 32, y * 32);

			else if (g->matrix[y][x] == 'P')
				set_player(g, x, y, dir);

			else if (g->matrix[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.exit, x * 32, y * 32);

			else
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.floor, x * 32, y * 32);
			x++;
		}
		y++;
	}
}


/*Funcion que inicializa minilibx, crea una ventana*/
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_errors2(5);
	game->mlx_win = mlx_new_window(game->mlx, game->w * TILE_PXL, \
	game->h * TILE_PXL, "so_long");
	//printf("W: %d\n H: %d", game->w, game->h);
}
