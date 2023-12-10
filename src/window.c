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

int	on_keypress(int keysym)
{
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

/*Funcion que setea las imgs*/
void	set_images(t_game *g)
{
	int	x;

	x = IMG_PXL;
	g->imgs.wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &x, &x);
	g->imgs.floor = mlx_xpm_file_to_image(g->mlx, "./textures/floor.xpm", &x, &x);
	g->imgs.cols = mlx_xpm_file_to_image(g->mlx, "./textures/cols.xpm", &x, &x);
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
	int		i;
	int		j;

	i = 0;
	while (i < g->h)
	{
		j = 0;
		while (j < g->w)
		{
			if (g->matrix[j][i] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.wall, j * 32, i * 32);

			else if (g->matrix[j][i] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.cols, g->w * j, g->h * i);

			else if (g->matrix[j][i] == 'P')
				set_player(g, g->w, g->h, dir);

			else if (g->matrix[j][i] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.exit, g->w * j, g->h * i);

			else
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, g->imgs.floor, g->w * j, g->h * i);
			j++;
		}
		i++;
	}
}

int	exit_game(t_game *g)
{
	ft_printf("GAME OVER!\n");
	mlx_destroy_window(g->mlx, g->mlx_win);
	exit(0);
}

/*Funcion que inicializa minilibx, crea una ventana*/
void	init_minilibx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_errors2(5);
	game->mlx_win = mlx_new_window(game->mlx, game->w * IMG_PXL, \
	game->h * IMG_PXL, "so_long");
}
