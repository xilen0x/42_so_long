
#include "../include/so_long.h"
#include "../include/window.h"

void	set_open_exit(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < game->h)
	{
		y = 0;
		while (y < game->w)
		{
			if (game->matrix[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, \
						game->mlx_win, game->imgs.open, x * 32, y * 32);
			y++;
		}
		x++;
	}
}

void	move_right(t_game *g)
{
	int	x;
	int	y;

	x = g->position.x;
	y = g->position.y;
	if (g->matrix[x - 1][y] >= 0 && g->matrix[x][y + 1] != '1')
	{
		ft_printf("******************************************\n");
		if (g->matrix[x][y + 1] == 'C')
			g->collected++;
		else if (g->matrix[x][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);
		else if (g->matrix[x][y + 1] == 'E')
			exit_game(g);
		g->matrix[x][y] = '0';
		g->matrix[x][y + 1] = 'P';
		g->walk_cnt++;
		//x = g->position.x;
		//y = g->position.y;
		set_images_to_win(g, 'd');
		//set_player(g, y, x, 'd');
		ft_printf("Steps N: %d\n", g->walk_cnt);
		ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
	{
		ft_printf("+++++++++++++++++++++\n");
	}
}
