
#include "../include/so_long.h"
#include "../include/window.h"

void	set_open_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->w)
	{
		x = 0;
		while (x < game->h)
		{
			if (game->matrix[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, \
						game->mlx_win, game->imgs.open, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	move_right(t_game *g)
{
	int	x;
	int	y;

	x = g->position.x;
	y = g->position.y;
	if (g->matrix[y - 1][x] >= 0 && g->matrix[y][x + 1] != '1')
	{
		if (g->matrix[y][x + 1] == 'C')
			g->collected++;
		if (g->matrix[y][x + 1] == 'E' && g->collected == g->q_collec)
			exit_game(g);
		else if (g->matrix[y][x + 1] != '1' && g->matrix[y][x + 1] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.x++;
			x = g->position.x;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'd');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			ft_printf("Collected N: %d\n", g->collected);
			ft_printf("Total to Collect: %d\n", g->q_collec);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
	else
		ft_printf("*** WALL ***\n");
}

void	move_up(t_game *g)
{
	int	x;
	int	y;

	x = g->position.x;
	y = g->position.y;
	if (g->matrix[y][x - 1] >= 0 && g->matrix[y - 1][x] != '1')
	{
		if (g->matrix[y - 1][x] == 'C')
			g->collected++;
		else if (g->matrix[y - 1][x] == 'E' && g->collected == g->q_collec)
			exit_game(g);
		else if ()//aki voy!!!!!!!!!!!
		{
			g->matrix[y][x] = '0';
			g->matrix[--y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'w');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			ft_printf("Collected N: %d\n", g->collected);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
	else
		ft_printf("*** WALL ***\n");
}

void	move_left(t_game *g)
{
	int	y;
	int	x;

	y = g->position.y;
	x = g->position.x;
	if (g->matrix[y - 1][x] >= 0 && g->matrix[y][x - 1] != '1')
	{
		if (g->matrix[y][x - 1] == 'C')
			g->collected++;
		if (g->matrix[y][x - 1] == 'E' && g->collected == g->q_collec)
			exit_game(g);	
		else if (g->matrix[y][x - 1] != '1' && g->matrix[y][x - 1] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.x--;
			x = g->position.x;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'a');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			ft_printf("Collected N: %d\n", g->collected);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
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
