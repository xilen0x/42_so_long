
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

	y = g->position.x;
	x = g->position.y;
	if (g->matrix[x - 1][y] >= 0 && g->matrix[x][y + 1] != '1')
	{
		if (g->matrix[x][y + 1] == 'C')
			g->collected++;
		else if (g->matrix[x][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);	
		g->matrix[x][y] = '0';
		g->matrix[x][++y] = 'P';
		g->walk_cnt++;
		g->position.x = y;
		g->position.y = x;
		set_images_to_win(g, 'd');
		//ft_printf("Steps N: %d\n", g->walk_cnt);
		//ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
		ft_printf("*** WALL ***\n");
}

void	move_up(t_game *g)
{
	int	x;
	int	y;

	y = g->position.x;
	x = g->position.y;
	if (g->matrix[x][y - 1] >= 0 && g->matrix[x - 1][y] != '1')
	{
		if (g->matrix[x - 1][y] == 'C')
			g->collected++;
		else if (g->matrix[x][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);	
		g->matrix[x][y] = '0';
		g->matrix[--x][y] = 'P';
		g->walk_cnt++;
		g->position.x = y;
		g->position.y = x;
		set_images_to_win(g, 'w');
		ft_printf("Steps N: %d\n", g->walk_cnt);
		ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
		ft_printf("*** WALL ***\n");
}

void	move_left(t_game *g)
{
	int	x;
	int	y;

	y = g->position.x;
	x = g->position.y;
	if (g->matrix[x - 1][y] >= 0 && g->matrix[x][y - 1] != '1')
	{
		if (g->matrix[x][y - 1] == 'C')
			g->collected++;
		else if (g->matrix[x][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);	
		g->matrix[x][y] = '0';
		g->matrix[x][--y] = 'P';
		g->walk_cnt++;
		g->position.x = y;
		g->position.y = x;
		set_images_to_win(g, 'a');
		ft_printf("Steps N: %d\n", g->walk_cnt);
		ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
		ft_printf("*** WALL ***\n");
}

void	move_down(t_game *g)
{
	int	x;
	int	y;

	y = g->position.x;
	x = g->position.y;
	if (g->matrix[x][y - 1] >= 0 && g->matrix[x + 1][y] != '1')
	{
		if (g->matrix[x + 1][y] == 'C')
			g->collected++;
		else if (g->matrix[x + 1][y] == 'E' && g->collected == g->q_collec)
			exit_game(g);	
		g->matrix[x][y] = '0';
		g->matrix[++x][y] = 'P';
		g->walk_cnt++;
		g->position.x = y;
		g->position.y = x;
		set_images_to_win(g, 's');
		ft_printf("Steps N: %d\n", g->walk_cnt);
		ft_printf("Collected N: %d\n", g->collected);
		if (g->collected == g->q_collec)
			set_open_exit(g);
	}
	else
		ft_printf("*** WALL ***\n");
}
