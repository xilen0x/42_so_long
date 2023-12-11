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

int	exit_game(t_game *g)
{
	write (1, "GAME OVER!\n", 11);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free(g->mlx);
	exit(0);
}

/*int	on_keypress(int keysym)
{
	printf("Pressed key: %d\\n", keysym);
	return (0);
}*/

// function that you want to call evety time you exit the game
/*int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}*/

/*int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		//on_destroy(game);
		exit_game(game);
	return (0);
}*/

/*Funcion que setea las imgs*/
void	set_images(t_game *g)
{
	int	x;

	x = TILE_PXL;
	g->imgs.wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &x, &x);
	g->imgs.floor = mlx_xpm_file_to_image(g->mlx, "./textures/floor.xpm", &x, &x);
	g->imgs.coll = mlx_xpm_file_to_image(g->mlx, "./textures/coll.xpm", &x, &x);
	g->imgs.exit = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &x, &x);
	g->imgs.open = mlx_xpm_file_to_image(g->mlx, "./textures/open.xpm", &x, &x);
	g->imgs.player.player_up = mlx_xpm_file_to_image(g->mlx, "./textures/player_up.xpm", &x, &x);
	g->imgs.player.player_right = mlx_xpm_file_to_image(g->mlx, "./textures/player_right.xpm", &x, &x);
	g->imgs.player.player_down = mlx_xpm_file_to_image(g->mlx, "./textures/player_down.xpm", &x, &x);
	g->imgs.player.player_left = mlx_xpm_file_to_image(g->mlx, "./textures/player_left.xpm", &x, &x);
}

void	set_player(t_game *g, int w, int h, char dir)
{
	if (dir == 'w')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_up, w * 32, h * 32);
	if (dir == 'a')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_left, w * 32, h * 32);
	if (dir == 's')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_down, w * 32, h * 32);
	if (dir == 'd')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_right, w * 32, h * 32);
}

void	set_images_to_win(t_game *g, char dir)
{
	int		x;
	int		y;

	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			if (g->matrix[y][x] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.wall, y * 32, x * 32);

			else if (g->matrix[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.coll, y * 32, x * 32);

			else if (g->matrix[y][x] == 'P')
				set_player(g, y, x, dir);

			else if (g->matrix[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.exit, y * 32, x * 32);

			else
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.floor, y * 32, x * 32);
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
	game->mlx_win = mlx_new_window(game->mlx, game->h * TILE_PXL, \
	game->w * TILE_PXL, "so_long");
}
