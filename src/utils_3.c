
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
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!aki voy, hay error al mover el muneco*/
	int	x;
	int	y;

	y = g->position.x;
	x = g->position.y;
	if (g->matrix[x - 1][y] >= 0 && g->matrix[x][y + 1] != '1')
	{
		ft_printf("*** ENTRA ***\n");
		if (g->matrix[x][y + 1] == 'C')
			g->collected++;
		else if (g->matrix[x][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);
		//printf("1: %d\n", g->matrix[x][y]);
		//printf("2: %d\n", g->matrix[x][y + 1]);
		g->matrix[x][y] = '0';
		g->matrix[x][y + 1] = 'P';
		g->walk_cnt++;
		g->position.x = y;
		g->position.y = x;
		set_images_to_win(g, 'd');
		//update_player_position(game, keycode);
		ft_printf("Steps N: %d\n", g->walk_cnt);
		ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
		ft_printf("*** NO ENTRA ***\n");
}

void	move_up(t_game *g)
{
	(void)g;
	ft_printf("UP!\n");
}

void	move_left(t_game *g)
{
	(void)g;
	ft_printf("LEFT!\n");
}

void	move_down(t_game *g)
{
	(void)g;
	ft_printf("DOWN!\n");
}