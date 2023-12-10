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
void	set_game(t_game *g)
{
	mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/floor.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/cols.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/open.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/player_up.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/player_right.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/player_down.xpm", &g->w, &g->h),
	mlx_xpm_file_to_image(g->mlx, "./textures/player_left.xpm", &g->w, &g->h);
	//g->w, g->h;
}

void	set_player(t_game *game, int w, int h, char dir)
{
	if (dir == 'w')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->imgs.player.player_up, w * 32, h * 32);
	if (dir == 'a')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->imgs.player.player_left, w * 32, h * 32);
	if (dir == 's')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->imgs.player.player_down, w * 32, h * 32);
	if (dir == 'd')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->imgs.player.player_right, w * 32, h * 32);
}

void	set_img(t_game *g, char dir)
{
	int		i;
	int		j;
	t_img	img;

	i = 0;
	while (i < g->h)
	{
		j = 0;
		while (j < g->w)
		{
			if (g->matrix[g->w + j][g->h] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, img.wall, g->w * 32, g->h * 32);

			else if (g->matrix[g->w + j][g->h] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, img.cols, g->w * 32, g->h * 32);

			else if (g->matrix[g->w + j][g->h] == 'P')
				set_player(g, g->w, g->h, dir);

			else if (g->matrix[g->w + j][g->h] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, img.exit, g->w * 32, g->h * 32);

			else
				mlx_put_image_to_window(g->mlx, \
						g->mlx_win, img.floor, g->w * 32, g->h * 32);
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
	game->mlx_win = mlx_new_window(game->mlx, game->w * IMG_PX, \
	game->h * IMG_PX, "so_long");
}
