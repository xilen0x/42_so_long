
#include "../include/so_long.h"
#include "../include/window.h"

void	set_open_exit(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (game->matrix[h * game->w + w][w] == 'E')
				mlx_put_image_to_window(game->mlx, \
						game->mlx_win, game->imgs.open, w * 32, h * 32);
			w++;
		}
		h++;
	}
}

void	move_w(t_game *g)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			while (i < g->h && g->matrix[y][x] != 'P')
				i++;
			if (g->matrix[y][x] == 'C')
				g->collected++;
			else if (g->matrix[i - y][x] == 'E' && g->collected == g->q_collec)
				exit_game(g);
			else if (g->matrix[i - y][x] != '1' && g->matrix[i - y][x] != 'E')
			{
				g->matrix[y][x] = '0';
				g->matrix[y][x] = 'P';
				g->walk_cnt++;
				ft_printf("%d\n", g->walk_cnt);
				set_images_to_win(g, 'w');
				if (g->collected == g->q_collec)
					set_open_exit(g);
			}
			x++;
		}
		y++;
	}
}
